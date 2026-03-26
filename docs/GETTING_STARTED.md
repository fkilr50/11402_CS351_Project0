# Getting Started

This guide will help you get up and running with the Two Sum project in minutes.

## Quick Start (5 minutes)

### Step 1: Install Dependencies
- Ensure you have a C++ compiler installed (g++, clang++, or MSVC)
- No other external libraries needed

### Step 2: Get the Code
```bash
git clone <repository-url>
cd 11402_CS351_Project0
```

### Step 3: Compile the Project
```bash
g++ -o twosum src/main.cpp src/twosum.cpp
```

### Step 4: Run It
```bash
./twosum
```

That's it! The program will prompt you for input.

## Your First Run

### Example Interactive Session

```
Enter array size: 4
Enter array elements (space-separated): 2 7 11 15
Enter target sum: 9

Result: Indices [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

## Project Structure Overview

```
11402_CS351_Project0/
├── README.md              # Project overview
├── src/
│   ├── main.cpp          # Program entry point - start here!
│   └── twosum.cpp        # Algorithm implementation
└── docs/
    └── [10 documentation files]
```

## What to Explore Next

### 1. **Understand the Algorithm** (10 min)
   - Read: [ARCHITECTURE.md](ARCHITECTURE.md)
   - Learn how the O(n) solution works
   - Understand the hash map approach

### 2. **Learn the API** (5 min)
   - Read: [API_REFERENCE.md](API_REFERENCE.md)
   - See function signatures
   - Check parameter requirements

### 3. **Try More Examples** (10 min)
   - Run: [USAGE.md](USAGE.md) examples
   - Test different inputs
   - Try edge cases

### 4. **Understand the Code** (15 min)
   - Open `src/main.cpp` and `src/twosum.cpp`
   - Follow the code comments
   - Trace through an example

## Common Tasks

### Want to contribute?
→ See [CONTRIBUTING.md](CONTRIBUTING.md)

### Having trouble?
→ Check [TROUBLESHOOTING.md](TROUBLESHOOTING.md)

### Running into issues?
→ Browse [FAQ.md](FAQ.md)

## Development Prerequisites

To modify and develop:

1. **C++ Compiler**
   - GCC: `apt-get install g++` (Linux)
   - Clang: `brew install llvm` (macOS)
   - MSVC: Install Visual Studio (Windows)

2. **Git**
   - For version control
   - Clone and manage branches

3. **Text Editor or IDE**
   - VS Code (recommended)
   - CLion
   - Any C++ capable editor

## Build Variants

### Debug Build (for development)
```bash
g++ -g -o twosum_debug src/main.cpp src/twosum.cpp
```

### Release Build (optimized)
```bash
g++ -O2 -o twosum src/main.cpp src/twosum.cpp
```

### With Warnings Enabled
```bash
g++ -Wall -Wextra -o twosum src/main.cpp src/twosum.cpp
```

## Branch Structure

This project uses:
- **main** - Stable, tested code
- **test** - Development/staging environment

See [CONTRIBUTING.md](CONTRIBUTING.md) when ready to work on features.

## Next Steps

1. ✅ **Compile and run** the program
2. **Try the examples** in [USAGE.md](USAGE.md)
3. **Read the source code** in `src/`
4. **Review the architecture** in [ARCHITECTURE.md](ARCHITECTURE.md)
5. **Consider contributing** per [CONTRIBUTING.md](CONTRIBUTING.md)

## Need Help?

- 📖 Read the relevant documentation file
- ❓ Check [FAQ.md](FAQ.md) for common questions
- 🐛 See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for issues
- 💬 Review [CONTRIBUTING.md](CONTRIBUTING.md) for development questions
