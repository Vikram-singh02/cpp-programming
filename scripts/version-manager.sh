#!/bin/bash

# Semantic Version Manager
# This script automatically updates version based on commit messages
# Follows Semantic Versioning (SemVer): MAJOR.MINOR.PATCH

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Get the current version from git tags
get_current_version() {
    local version=$(git describe --tags --abbrev=0 2>/dev/null || echo "v0.0.0")
    echo ${version#v}  # Remove 'v' prefix
}

# Parse version into components
parse_version() {
    local version=$1
    IFS='.' read -ra VERSION_PARTS <<< "$version"
    MAJOR=${VERSION_PARTS[0]:-0}
    MINOR=${VERSION_PARTS[1]:-0}
    PATCH=${VERSION_PARTS[2]:-0}
}

# Increment version based on type
increment_version() {
    local bump_type=$1
    parse_version $(get_current_version)
    
    case $bump_type in
        "major")
            MAJOR=$((MAJOR + 1))
            MINOR=0
            PATCH=0
            ;;
        "minor")
            MINOR=$((MINOR + 1))
            PATCH=0
            ;;
        "patch")
            PATCH=$((PATCH + 1))
            ;;
        *)
            echo -e "${RED}Error: Invalid bump type. Use major, minor, or patch.${NC}"
            exit 1
            ;;
    esac
    
    echo "${MAJOR}.${MINOR}.${PATCH}"
}

# Analyze commit messages since last tag
analyze_commits() {
    local last_tag=$(git describe --tags --abbrev=0 2>/dev/null || echo "")
    local commit_range
    
    if [ -z "$last_tag" ]; then
        commit_range="HEAD"
    else
        commit_range="${last_tag}..HEAD"
    fi
    
    local commits=$(git log $commit_range --oneline --no-merges)
    
    if [ -z "$commits" ]; then
        echo "patch"  # Default to patch if no commits
        return
    fi
    
    # Check for breaking changes (major version) - case insensitive
    if echo "$commits" | grep -q -iE "BREAKING|breaking.change|major:|^[^:]*:\s*BREAKING"; then
        echo "major"
        return
    fi
    
    # Check for new features (minor version)
    if echo "$commits" | grep -q -iE "feat|feature|add:|new:|minor:|^[^:]*:\s*(feat|feature|add|new)"; then
        echo "minor"
        return
    fi
    
    # Default to patch for fixes, docs, refactor, etc.
    echo "patch"
}

# Create or update VERSION file
update_version_file() {
    local version=$1
    cat > VERSION << EOF
# Version Information
VERSION=$version
RELEASE_DATE=$(date -u +"%Y-%m-%d %H:%M:%S UTC")
COMMIT_HASH=$(git rev-parse HEAD)
BRANCH=$(git rev-parse --abbrev-ref HEAD)

# Semantic Versioning Rules:
# MAJOR version: Breaking changes, incompatible API changes
# MINOR version: New features, backwards compatible
# PATCH version: Bug fixes, backwards compatible

# Commit Keywords:
# feat/feature/add/new/minor: -> Minor version bump
# fix/patch/bug: -> Patch version bump  
# BREAKING/major: -> Major version bump
EOF
    echo -e "${GREEN}✅ VERSION file updated to v$version${NC}"
}

# Create git tag
create_tag() {
    local version=$1
    local tag_name="v$version"
    
    git tag -a "$tag_name" -m "Release version $version

$(git log $(git describe --tags --abbrev=0 2>/dev/null || echo "")..HEAD --oneline --no-merges || echo "Initial release")"
    
    echo -e "${GREEN}✅ Created git tag: $tag_name${NC}"
}

# Main function
main() {
    echo -e "${BLUE}🔍 Analyzing commit history for version bumping...${NC}"
    
    local current_version=$(get_current_version)
    echo -e "${YELLOW}📋 Current version: v$current_version${NC}"
    
    local bump_type=$(analyze_commits)
    echo -e "${YELLOW}📈 Detected change type: $bump_type${NC}"
    
    local new_version=$(increment_version $bump_type)
    echo -e "${GREEN}🚀 New version: v$new_version${NC}"
    
    # Update VERSION file
    update_version_file $new_version
    
    # Add VERSION file to git
    git add VERSION
    
    # Create tag
    create_tag $new_version
    
    echo -e "${GREEN}🎉 Version management completed!${NC}"
    echo -e "${BLUE}📝 To push tags to remote: git push origin --tags${NC}"
}

# Show help
show_help() {
    echo "Semantic Version Manager"
    echo ""
    echo "Usage: $0 [command]"
    echo ""
    echo "Commands:"
    echo "  auto        Automatically determine version bump from commits (default)"
    echo "  major       Force major version bump"
    echo "  minor       Force minor version bump" 
    echo "  patch       Force patch version bump"
    echo "  current     Show current version"
    echo "  help        Show this help"
    echo ""
    echo "Commit message keywords:"
    echo "  feat, feature, add, new, minor: -> Minor version bump"
    echo "  fix, patch, bug: -> Patch version bump"
    echo "  BREAKING, major: -> Major version bump"
}

# Handle command line arguments
case "${1:-auto}" in
    "auto")
        main
        ;;
    "major"|"minor"|"patch")
        current_version=$(get_current_version)
        new_version=$(increment_version $1)
        echo -e "${GREEN}🚀 Bumping version from v$current_version to v$new_version${NC}"
        update_version_file $new_version
        git add VERSION
        create_tag $new_version
        ;;
    "current")
        echo "v$(get_current_version)"
        ;;
    "help"|"-h"|"--help")
        show_help
        ;;
    *)
        echo -e "${RED}Error: Unknown command '$1'${NC}"
        show_help
        exit 1
        ;;
esac
