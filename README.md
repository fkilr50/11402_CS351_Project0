# 11402_CS351_Project0 - Two Sum Problem Solver

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Version](https://img.shields.io/badge/version-1.0.0-green.svg)](CHANGELOG.md)
[![C++](https://img.shields.io/badge/C++-11+-blue.svg)](#)

## 📋 Overview

This is a C++ implementation of the classic **Two Sum** algorithmic problem. Given an array of integers and a target sum, the program efficiently finds two distinct indices where the elements sum to the target value.

**Problem Statement:**  
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to `target`. You cannot use the same element twice.

### Example
```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

## ⚡ Algorithm Highlights

- **Time Complexity:** O(n) - Linear time with single pass
- **Space Complexity:** O(n) - Hash map storage
- **Approach:** Hash map based solution
- **Language:** C++11 or higher

## 📂 Project Structure

```
11402_CS351_Project0/
├── README.md                    # This file - Project overview
├── src/
│   ├── main.cpp                # Program entry point
│   └── twosum.cpp              # Algorithm implementation
└── docs/
    ├── API_REFERENCE.md         # Function documentation
    ├── ARCHITECTURE.md          # Design and structure
    ├── CHANGELOG.md             # Version history
    ├── CONTRIBUTING.md          # Contribution guidelines
    ├── FAQ.md                   # Frequently asked questions
    ├── GETTING_STARTED.md       # Quick start guide
    ├── INSTALLATION.md          # Setup instructions
    ├── TROUBLESHOOTING.md       # Common issues & solutions
    └── USAGE.md                 # Usage examples
```

## 🚀 Quick Start

### Prerequisites
- C++ compiler (GCC 4.8+, Clang 3.3+, or MSVC 2015+)
- GNU Make (optional)

### Installation

```bash
# Clone the repository
git clone <repository-url>
cd 11402_CS351_Project0

# Compile
g++ -o twosum src/main.cpp src/twosum.cpp

# Run
./twosum          # Linux/macOS
twosum.exe        # Windows
```

See [INSTALLATION.md](docs/INSTALLATION.md) for detailed setup instructions.

### Usage Example

```bash
$ ./twosum
Enter array size: 4
Enter array elements (space-separated): 2 7 11 15
Enter target sum: 9

Result: Indices [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

For more examples, see [USAGE.md](docs/USAGE.md).

## 📚 Documentation

Comprehensive documentation is available:

| Document | Purpose |
|----------|----------|
| [GETTING_STARTED.md](docs/GETTING_STARTED.md) | Quick start in 5 minutes |
| [INSTALLATION.md](docs/INSTALLATION.md) | Platform-specific setup |
| [USAGE.md](docs/USAGE.md) | Usage examples and test cases |
| [API_REFERENCE.md](docs/API_REFERENCE.md) | Function signatures and documentation |
| [ARCHITECTURE.md](docs/ARCHITECTURE.md) | Design decisions and structure |
| [CONTRIBUTING.md](docs/CONTRIBUTING.md) | How to contribute |
| [FAQ.md](docs/FAQ.md) | Common questions |
| [TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md) | Issue diagnosis and solutions |
| [CHANGELOG.md](docs/CHANGELOG.md) | Version history |

## 🔄 Version Control Strategy

### Branches

- **main** - Production-ready, stable code
  - Contains thoroughly tested implementations
  - Ready for submission or deployment
  - No direct feature commits

- **test** - Staging/Development environment
  - Used for testing new features
  - Code validation and QA occurs here
  - All tests must pass before merging to main

### Workflow

1. Create feature branches from `test` branch
2. Implement and test changes
3. Submit PR to `test` branch
4. After review and passing all tests, merge to `main`

See [CONTRIBUTING.md](docs/CONTRIBUTING.md) for detailed contribution guidelines.

## 📋 Code Standards

This project adheres to the **Google C++ Style Guide** covering:

- 2-space indentation
- `snake_case` for variables and functions
- `CamelCase` for classes and types
- Comprehensive documentation
- Clear, self-documenting code

See [CONTRIBUTING.md](docs/CONTRIBUTING.md#code-style) for style guidelines.

## 🛠️ Development Setup

### For Contributors

```bash
# Setup development environment
git clone <repository-url>
cd 11402_CS351_Project0

# Compile with debug symbols and warnings
g++ -std=c++11 -Wall -Wextra -g -o twosum_dev src/main.cpp src/twosum.cpp

# Test the build
./twosum_dev
```

For more details, see [CONTRIBUTING.md](docs/CONTRIBUTING.md).

## 📊 Algorithm Explanation

### Why Hash Map?

The problem can be solved in multiple ways:

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Sort + Two Pointers | O(n log n) | O(1) | Loses original indices |
| **Hash Map** | **O(n)** | **O(n)** | **Optimal solution** |

The hash map approach:
1. Stores each number and its index as we iterate
2. For each number, checks if its complement exists in O(1) time
3. Returns indices immediately upon finding the pair

## ❓ Common Questions

**Q: Can I use the same element twice?**  
A: No. The indices must be distinct (i ≠ j).

**Q: What if multiple solutions exist?**  
A: The algorithm returns the first valid pair found.

**Q: Does it work with negative numbers?**  
A: Yes, fully supported.

**Q: What about duplicates in the array?**  
A: Handled correctly as long as indices are different.

For more Q&A, see [FAQ.md](docs/FAQ.md).

## 🆘 Troubleshooting

Common issues and solutions:

- **Compilation errors** → See [TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md#compilation-issues)
- **Runtime errors** → See [TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md#runtime-issues)
- **Wrong results** → See [TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md#logic-issues)

## 📝 Contributing

We welcome contributions! Please:

1. Read [CONTRIBUTING.md](docs/CONTRIBUTING.md)
2. Fork the repository
3. Create a feature branch from `test`
4. Submit a pull request with clear description

## 📜 License

MIT License - See LICENSE file for details

## 👤 Author

**Student ID:** 11402  
**Course:** CS351 - Programming Fundamentals  
**Semester:** 6

## 🔗 Links

- [Quick Start Guide](docs/GETTING_STARTED.md)
- [Installation Instructions](docs/INSTALLATION.md)
- [Usage Examples](docs/USAGE.md)
- [Contributing Guide](docs/CONTRIBUTING.md)
- [FAQ](docs/FAQ.md)
- [Troubleshooting](docs/TROUBLESHOOTING.md)
- [API Reference](docs/API_REFERENCE.md)
- [Architecture](docs/ARCHITECTURE.md)
- [Changelog](docs/CHANGELOG.md)

---

**Last Updated:** March 26, 2026  
**Version:** 1.0.0  
**Status:** ✅ Production Ready

