# Automated Semantic Versioning System

This repository uses an automated semantic versioning system that updates versions based on commit messages.

## 🎯 How It Works

The system automatically analyzes your commit messages and updates the version number according to [Semantic Versioning](https://semver.org/) rules:

- **MAJOR** version (X.y.z): Breaking changes, incompatible API changes
- **MINOR** version (x.Y.z): New features, backwards compatible  
- **PATCH** version (x.y.Z): Bug fixes, backwards compatible

## 🔍 Commit Message Keywords

### Minor Version Bump (New Features)
- `feat:` - New feature
- `feature:` - New feature  
- `add:` - Adding new functionality
- `new:` - New addition
- `minor:` - Explicit minor bump

### Patch Version Bump (Bug Fixes)
- `fix:` - Bug fix
- `patch:` - Patch/small fix
- `bug:` - Bug fix
- `docs:` - Documentation changes
- `refactor:` - Code refactoring
- `test:` - Adding tests

### Major Version Bump (Breaking Changes)
- `BREAKING:` - Breaking change
- `breaking change:` - Breaking change
- `major:` - Explicit major bump

## 📝 Example Commit Messages

```bash
# Minor version bump (0.1.0 → 0.2.0)
git commit -m "feat: add search functionality to double linked list"

# Patch version bump (0.1.0 → 0.1.1)  
git commit -m "fix: resolve memory leak in destructor"

# Major version bump (0.1.0 → 1.0.0)
git commit -m "BREAKING: change LinkedList API for better compatibility"
```

## 🛠️ Manual Version Management

You can also manually control versioning:

```bash
# Check current version
./scripts/version-manager.sh current

# Force specific version bumps
./scripts/version-manager.sh major   # 1.0.0 → 2.0.0
./scripts/version-manager.sh minor   # 1.0.0 → 1.1.0  
./scripts/version-manager.sh patch   # 1.0.0 → 1.0.1

# Auto-detect from commit history
./scripts/version-manager.sh auto
```

## 📁 Generated Files

The system creates/updates these files:

### `VERSION` file
Contains version information:
```
VERSION=1.2.3
RELEASE_DATE=2025-08-25 10:30:00 UTC
COMMIT_HASH=abc123def456
BRANCH=main
```

### Git Tags
Automatically creates git tags:
- `v1.0.0`
- `v1.1.0`
- `v1.1.1`

## ⚡ Automation Features

### GitHub Actions Integration
- **Automatic versioning** on every push to main
- **Release creation** with proper version numbers
- **Artifact generation** with version tags

### Git Hooks
- **Pre-commit hook** ensures version is updated
- **Automatic tagging** on version changes

## 🚀 CI/CD Integration

### Automatic Workflow
1. Developer commits with semantic message
2. System detects change type
3. Version number is updated
4. Git tag is created
5. CI/CD pipeline builds and tests
6. Release artifacts are generated

### Manual Release
1. Go to GitHub Actions
2. Run "Manual Release" workflow
3. Choose version bump type
4. Add release notes
5. System creates official release

## 📊 Version History

All versions are tracked through:
- Git tags
- VERSION file history
- GitHub Releases
- CI/CD artifacts

## 🔧 Setup

The versioning system is already configured! Just start committing with semantic messages:

```bash
# Make changes to your code
git add .
git commit -m "feat: implement new double linked list functionality"
git push origin main
```

The version will be automatically updated and tagged! 🎉
