#!/bin/bash

# Demo script for semantic versioning system
echo "🎯 C++ Programming Repository - Semantic Versioning Demo"
echo "=================================================="

echo ""
echo "📋 Current repository status:"
echo "- Repository: cpp-programming"
echo "- Current version: $(./scripts/version-manager.sh current 2>/dev/null || echo 'v0.0.0')"
echo "- Current branch: $(git rev-parse --abbrev-ref HEAD)"

echo ""
echo "🔍 Semantic Versioning Rules:"
echo "- feat/feature/add/new/minor: → Minor version bump (x.Y.z)"
echo "- fix/patch/bug: → Patch version bump (x.y.Z)"
echo "- BREAKING/major: → Major version bump (X.y.z)"

echo ""
echo "💡 Example commit messages:"
echo "- 'feat: add search functionality to linked list'"
echo "- 'fix: resolve memory leak in destructor'"  
echo "- 'BREAKING: change API interface for compatibility'"

echo ""
echo "🚀 How to use:"
echo "1. Make your changes"
echo "2. Commit with semantic keywords"
echo "3. Version is automatically updated"
echo "4. Push to trigger CI/CD"

echo ""
echo "⚡ Manual version management:"
echo "- ./scripts/version-manager.sh major   # Force major bump"
echo "- ./scripts/version-manager.sh minor   # Force minor bump" 
echo "- ./scripts/version-manager.sh patch   # Force patch bump"
echo "- ./scripts/version-manager.sh current # Show current version"

echo ""
echo "✅ Setup complete! The versioning system is ready to use."
