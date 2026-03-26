# Troubleshooting Guide

This guide helps resolve common issues with the Two Sum project.

## Compilation Issues

### Error: "g++: command not found"

**Problem:** C++ compiler is not installed or not in PATH.

**Solutions:**

**Windows:**
- Download MinGW from [mingw-w64.org](https://mingw-w64.org)
- Add to PATH: `C:\mingw64\bin`
- Verify: Open cmd, type `g++ --version`

**macOS:**
```bash
brew install gcc
# or
xcode-select --install
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install g++
```

---

### Error: "No such file or directory: src/main.cpp"

**Problem:** Working directory is wrong or files are missing.

**Solutions:**
```bash
# Check current directory
pwd

# Navigate to project root
cd path/to/11402_CS351_Project0

# Verify files exist
ls -la src/        # Linux/macOS
dir src            # Windows
```

---

### Error: "undefined reference to `twoSum'"

**Problem:** Not including both source files in compilation.

**Solution:**
```bash
# WRONG - missing twosum.cpp
g++ -o twosum src/main.cpp

# CORRECT - includes both files
g++ -o twosum src/main.cpp src/twosum.cpp
```

---

### Error: "error: 'vector' was not declared"

**Problem:** Missing `#include <vector>` or using old C++ standard.

**Solutions:**

**Verify includes in source files:**
```cpp
#include <vector>
#include <unordered_map>
#include <iostream>
```

**Compile with C++11:**
```bash
g++ -std=c++11 -o twosum src/main.cpp src/twosum.cpp
```

---

## Runtime Issues

### Error: "Permission denied" when running executable

**Problem (Linux/macOS):** Executable doesn't have execute permission.

**Solution:**
```bash
chmod +x twosum
./twosum
```

---

### Program crashes immediately

**Problem:** Segmentation fault or unhandled exception.

**Debugging steps:**
```bash
# 1. Compile with debug symbols
g++ -g -o twosum_debug src/main.cpp src/twosum.cpp

# 2. Run with debugger
gdb ./twosum_debug
(gdb) run
[enter inputs]
(gdb) bt  # Print backtrace
```

**Common causes:**
- Invalid array input (non-integers)
- Empty array
- Array too small

---

### Program produces wrong results

**Problem:** Output doesn't match expected values.

**Debug checklist:**
```cpp
// Add debug output to see what's happening
std::cout << "Input array: ";
for (int num : nums) std::cout << num << " ";
std::cout << "\nTarget: " << target << std::endl;

// Check result
std::vector<int> result = twoSum(nums, target);
if (result.size() == 2) {
  std::cout << "nums[" << result[0] << "] + nums[" << result[1] << "] = "
            << nums[result[0]] << " + " << nums[result[1]] << " = "
            << (nums[result[0]] + nums[result[1]]) << std::endl;
}
```

**Verify your expectation:**
- Does nums[index1] + nums[index2] actually equal target?
- Are indices different (i ≠ j)?
- Are indices within bounds (0 to array.size()-1)?

---

## Input Validation Issues

### "Invalid input" error

**Problem:** Program rejected your input.

**Common causes and fixes:**

| Issue | Example | Fix |
|-------|---------|-----|
| Non-integer array | `2 a 11 15` | Use only integers: `2 7 11 15` |
| Too few elements | `5` | Array needs 2+ elements: `2 7` |
| Invalid format | `2, 7, 11` | Use spaces not commas: `2 7 11` |
| Empty input | (blank line) | Enter values: `2 7 11 15` |

**Correct input format:**
```
Array size: 4
Array elements: 2 7 11 15
Target sum: 9
```

---

### "No solution found" but I expect one

**Problem:** Algorithm returned empty result.

**Verify:**
1. Are there actually two numbers that sum to target?
   ```bash
   # Example: [2, 7, 11, 15], target 9
   # Check: 2+7=9 ✓
   ```

2. Are the numbers at different indices?
   ```bash
   # Wrong: [5, 5], target 10 might need indices 0,0 (NOT allowed)
   # Right: [5, 5], target 10 with different 5's at indices 0,1 (OK)
   ```

3. Try a known working example:
   ```
   Array: 2 7 11 15
   Target: 9
   Expected: [0, 1]
   ```

---

## Logic Issues

### Off-by-one errors

**Problem:** Results show index off by 1.

**Remember:**
- C++ uses 0-based indexing
- First element is at index 0, not 1
- Array of size 4 has indices: 0, 1, 2, 3

```cpp
// Example:
std::vector<int> nums = {2, 7, 11, 15};
// Index:                 0  1   2   3
// Value:                 2  7  11  15
```

---

### Handling duplicates

**Problem:** Array has duplicate numbers.

**Example:**
```
Array: [1, 2, 2, 7], target 4
Solution: [1, 3] (nums[1]=2, nums[3]=7)
Also valid: [2, 3] if that's found first
NOT valid: [1, 2] (same 2 at different indices)
```

**Note:** Current algorithm handles this correctly.

---

## Performance Issues

### Program is slow with large arrays

**Problem:** Noticeable delay with 10,000+ elements.

**Analysis:**
- O(n) algorithm is already optimal
- Delay likely from I/O, not algorithm
- Consider:
  - Input reading time
  - Output printing time
  - System load

**Optimizations:**
```bash
# Release build (optimized)
g++ -O2 -o twosum src/main.cpp src/twosum.cpp

# Avoid excessive output
# Use buffered I/O
```

---

### High memory usage

**Problem:** Program uses lots of RAM.

**Cause:** Hash map stores all elements (O(n) space).

**Context:**
- For 10,000 integers: ~40KB for array + ~40KB+ for hash map
- This is normal and acceptable
- Not excessive for modern systems

**If truly problematic:**
- Consider alternative algorithms (not recommended)
- Check for memory leaks with valgrind

---

## Git/Version Control Issues

### "Branch not found"

**Problem:** Can't checkout expected branch.

**Solutions:**
```bash
# List all branches
git branch -a

# Fetch latest branches
git fetch origin

# Checkout correct branch
git checkout test
```

---

### "Merge conflicts"

**Problem:** Can't merge due to conflicts.

**Steps:**
```bash
# View conflicts
git status

# Open conflicted files and resolve manually
# Marked with <<<<<<, ======, >>>>>>>

# After resolving
git add resolved_file.cpp
git commit -m "Resolve merge conflict"
```

---

## Platform-Specific Issues

### Windows: `twosum.exe` not found

**Solution:**
```cmd
# Compile creates .exe file
g++ -o twosum.exe src/main.cpp src/twosum.cpp

# Run the .exe
twosum.exe

# Or just in Windows:
twosum  # .exe added automatically
```

---

### macOS: "xcrun: error: unable to find utility"

**Solution:**
```bash
xcode-select --install
# Or
brew install gcc
```

---

### Linux: Library not found

**Solution:**
```bash
# Standard library should be available
# If getting linking errors:
sudo apt-get install libstdc++6

# Compile explicitly
g++ -v -o twosum src/main.cpp src/twosum.cpp
```

---

## Still Having Issues?

1. **Review relevant docs:**
   - [FAQ.md](FAQ.md) - Common questions
   - [INSTALLATION.md](INSTALLATION.md) - Setup help
   - [GETTING_STARTED.md](GETTING_STARTED.md) - Quick start

2. **Check examples:**
   - See [USAGE.md](USAGE.md) for working examples

3. **Verify setup:**
   - Follow [INSTALLATION.md](INSTALLATION.md) step-by-step
   - Ensure compiler is installed: `g++ --version`
   - Verify files exist: `ls -la src/`

4. **Enable verbose output:**
   ```bash
   g++ -v -Wall -Wextra -o twosum src/main.cpp src/twosum.cpp
   ```

5. **Debug step-by-step:**
   - Use gdb for source-level debugging
   - Add cout statements for tracking execution
   - Verify input before processing
