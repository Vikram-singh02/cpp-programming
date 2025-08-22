# CI/CD Pipeline Documentation

This repository uses GitHub Actions for continuous integration and deployment.

## Pipeline Overview

The CI/CD pipeline automatically:
1. **Builds** the C++ projects on every push/PR
2. **Tests** the functionality with automated test scripts
3. **Creates artifacts** with compiled binaries
4. **Creates releases** on main branch pushes

## Workflow Details

### Triggers
- **Push** to `main` or `develop` branches
- **Pull Requests** to `main` branch

### Jobs

#### 1. Build and Test (`build-and-test`)
- Runs on Ubuntu latest
- Installs build dependencies (g++, make)
- Compiles the Basic Linked List project
- Runs automated tests
- Uploads artifacts

#### 2. Create Release (`create-release`)
- Only runs on main branch pushes
- Creates a release package
- Generates automatic release tags
- Uploads release artifacts to GitHub Releases

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
