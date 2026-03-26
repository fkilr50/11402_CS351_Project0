# Installation Guide

## Prerequisites

Before installing, ensure you have:

### Required
- **C++ Compiler** (C++11 or higher)
  - GCC 4.8+
  - Clang 3.3+
  - MSVC 2015+
- **Git** (for cloning repository)
- **100MB** disk space

### Optional
- IDE or Text Editor (VS Code recommended)
- Make or CMake (for larger projects)

## Platform-Specific Installation

### Windows

#### Option 1: Using MinGW
```bash
# Download and install MinGW from mingw-w64.org
# Add to PATH
# Verify installation
g++ --version

# Clone repository
git clone <repository-url>
cd 11402_CS351_Project0

# Compile
g++ -o twosum.exe src/main.cpp src/twosum.cpp

# Run
twosum.exe
```

#### Option 2: Using Visual Studio
```bash
# Open Visual Studio
# Create new C++ Console Project
# Add src/main.cpp and src/twosum.cpp to project
# Build (Ctrl+Shift+B)
# Run (F5)
```

#### Option 3: Using WSL (Windows Subsystem for Linux)
```bash
# Install WSL2 if not already installed
wsl --install

# In WSL terminal, follow Linux instructions below
```

### macOS

#### Using Homebrew
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or install via Homebrew
brew install gcc

# Clone repository
git clone <repository-url>
cd 11402_CS351_Project0

# Compile
g++ -o twosum src/main.cpp src/twosum.cpp

# Run
./twosum
```

#### Using Clang (included with Xcode)
```bash
xcode-select --install
clang++ -o twosum src/main.cpp src/twosum.cpp
./twosum
```

### Linux

#### Debian/Ubuntu
```bash
# Install compiler
sudo apt-get update
sudo apt-get install g++ git

# Clone repository
git clone <repository-url>
cd 11402_CS351_Project0

# Compile
g++ -o twosum src/main.cpp src/twosum.cpp

# Run
./twosum
```

#### Fedora/RHEL
```bash
# Install compiler
sudo dnf install gcc-c++ git

# Clone repository
git clone <repository-url>
cd 11402_CS351_Project0

# Compile
g++ -o twosum src/main.cpp src/twosum.cpp

# Run
./twosum
```

#### Arch Linux
```bash
# Install compiler
sudo pacman -S base-devel git

# Clone repository
git clone <repository-url>
cd 11402_CS351_Project0

# Compile
g++ -o twosum src/main.cpp src/twosum.cpp

# Run
./twosum
```

## Verification

After installation, verify everything works:

### Test Compilation
```bash
# Compile with compiler version info
g++ --version

# Compile the project
g++ -o twosum src/main.cpp src/twosum.cpp

# Check executable was created
ls -la twosum  # Linux/macOS
dir twosum.exe # Windows
```

### Test Execution
```bash
# Run the program
./twosum  # Linux/macOS
twosum.exe # Windows

# Try this input when prompted:
# Array: 2 7 11 15
# Target: 9
# Expected output: [0, 1]
```

## Build Options

### Basic Compilation
```bash
g++ -o twosum src/main.cpp src/twosum.cpp
```

### Debug Build (includes debug symbols)
```bash
g++ -g -o twosum_debug src/main.cpp src/twosum.cpp
```

### Optimized Release Build
```bash
g++ -O2 -o twosum src/main.cpp src/twosum.cpp
```

### With All Warnings
```bash
g++ -Wall -Wextra -Wpedantic -o twosum src/main.cpp src/twosum.cpp
```

### C++11 Explicitly
```bash
g++ -std=c++11 -o twosum src/main.cpp src/twosum.cpp
```

### Full Development Build
```bash
g++ -std=c++11 -Wall -Wextra -g -o twosum_dev src/main.cpp src/twosum.cpp
```

## Using Make (Optional)

Create a `Makefile` in project root:

```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = twosum
SOURCES = src/main.cpp src/twosum.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
```

Then use:
```bash
make          # Compile
make clean    # Clean build artifacts
```

## Troubleshooting Installation

### "g++ command not found"
**Solution:** Install C++ compiler for your platform (see platform sections above)

### "No such file or directory: src/main.cpp"
**Solution:** Ensure you're in the project root directory. Run `pwd` (Linux/macOS) or `cd` (Windows) to verify.

### Compilation errors
**Solution:** 
- Verify C++ version: `g++ --version`
- Check file existence: `ls src/`
- Try: `g++ -std=c++11 -Wall`

### "Permission denied" when running executable
**Solution (Linux/macOS):**
```bash
chmod +x twosum
./twosum
```

## Next Steps

1. ✅ Installation complete
2. 📖 Read [GETTING_STARTED.md](GETTING_STARTED.md)
3. 🚀 Try [USAGE.md](USAGE.md) examples
4. 🔍 Review [ARCHITECTURE.md](ARCHITECTURE.md)

## Getting Help

- See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for common issues
- Check [FAQ.md](FAQ.md) for installation questions
- Review [CONTRIBUTING.md](CONTRIBUTING.md) for development setup
