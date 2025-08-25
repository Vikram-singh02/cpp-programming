# C++ Programming Examples

![CI/CD Pipeline](https://github.com/Vikram-singh02/cpp-programming/actions/workflows/ci-cd.yml/badge.svg)
![Version](https://img.shields.io/github/v/tag/Vikram-singh02/cpp-programming?label=version)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

This repository contains various C++ programming examples and implementations, focusing on fundamental data structures and algorithms with modern development practices.

## 🚀 Features

- **Automated Semantic Versioning** - Version bumps based on commit messages
- **CI/CD Pipeline** - Automated building, testing, and releases
- **Comprehensive Testing** - Automated test suites for all implementations
- **Interactive Programs** - Menu-driven interfaces for easy testing
- **Documentation** - Detailed README for each project

## 🎯 Semantic Versioning

This project uses automated semantic versioning:
- `feat:` → Minor version bump (new features)
- `fix:` → Patch version bump (bug fixes)  
- `BREAKING:` → Major version bump (breaking changes)

Current version: **v1.0.1**

📖 [Complete Versioning Guide](docs/VERSIONING.md)

## 📁 Projects

### [Basic Linked List](basic_linked_list/)
A clean implementation of a singly linked list data structure with:
- ✅ Interactive menu system (7 operations)
- ✅ Insert, delete, search, and display operations
- ✅ Memory management and error handling
- ✅ Comprehensive test suite

### [Double Linked List](double_linked_list/) ⭐ **NEW**
Advanced bidirectional linked list implementation featuring:
- ✅ Forward and backward navigation
- ✅ Insert after specific value functionality  
- ✅ Position-based operations (13 total operations)
- ✅ Enhanced interactive menu with reverse display
- ✅ Advanced error handling and validation

## 🛠️ Quick Start

```bash
# Clone the repository
git clone https://github.com/Vikram-singh02/cpp-programming.git
cd cpp-programming

# Build any project
cd basic_linked_list    # or double_linked_list
make
./linkedlist           # or ./double_linkedlist

# Run tests
./test.sh
```

## 🔧 Development

### Building All Projects
```bash
# Basic Linked List
cd basic_linked_list && make && cd ..

# Double Linked List  
cd double_linked_list && make && cd ..
```

### Running Tests
```bash
# Test basic linked list
cd basic_linked_list && ./test.sh && cd ..

# Test double linked list
cd double_linked_list && ./test.sh && cd ..
```

## 📚 Documentation

- 📖 [Versioning Guide](docs/VERSIONING.md) - Semantic versioning system
- 🔧 [CI/CD Documentation](docs/CI-CD.md) - Pipeline details
- 📋 Individual project READMEs in each directory

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feat/new-feature`
3. Commit with semantic messages: `git commit -m "feat: add new feature"`
4. Push to your branch: `git push origin feat/new-feature`
5. Create a Pull Request

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.
