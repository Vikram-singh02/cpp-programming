# CI/CD Pipeline Documentation

This document describes the GitHub Actions CI/CD pipeline for the C++ Programming repository.

## Pipeline Overview

The CI/CD pipeline automatically:
1. **Builds** the C++ projects on every push/PR
2. **Tests** the functionality with automated test scripts
3. **Creates artifacts** with compiled binaries
4. **Packages releases** for distribution
5. **Manages semantic versioning** automatically

## Workflows

### 1. Main CI/CD Pipeline (`ci-cd.yml`)
**Triggers:**
- Push to `main` or `develop` branches
- Pull Requests to `main` branch

**Jobs:**
- `build-and-test`: Compiles and tests the code
- `build-artifacts`: Creates release packages (only on main branch)

### 2. Manual Release (`manual-release.yml`)
**Triggers:**
- Manual trigger from GitHub Actions tab
- Allows custom version numbers and release notes

**Features:**
- Custom version tagging
- Personalized release notes
- Creates official GitHub releases
- Comprehensive testing before release

### Artifacts
- Compiled binaries are stored as artifacts for 30 days
- Release packages include source code and documentation

## Local Testing

You can run the same tests locally:

```bash
cd basic_linked_list
make clean && make
./test.sh
```

## Test Coverage

The automated tests verify:
- ✅ Program compilation
- ✅ Basic insert/display operations
- ✅ Search functionality
- ✅ Size calculation
- ✅ Invalid input handling
- ✅ Program startup/shutdown

## Release Process

Releases are automatically created when code is pushed to the main branch. Each release includes:
- Compiled executable
- Complete source code
- Documentation
- Build instructions

Release tags follow the format: `vYYYY.MM.DD-{commit-hash}`
