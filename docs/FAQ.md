# Frequently Asked Questions (FAQ)

## General Questions

### Q: What does this project do?
**A:** This project solves the "Two Sum" problem: given an array of integers and a target sum, it finds two distinct numbers in the array that add up to the target and returns their indices.

### Q: Why use a hash map solution?
**A:** The hash map approach provides:
- Time Complexity: O(n) - much faster than brute force O(n²)
- Single pass through the array
- Average O(1) lookup time
- Trade-off: Uses O(n) extra space

### Q: Can I use the same element twice?
**A:** No. The two numbers must be at different indices (i ≠ j).

### Q: What if there are multiple valid solutions?
**A:** The algorithm returns the first valid pair found during iteration.

### Q: What if no solution exists?
**A:** The function returns an empty vector.

## Installation & Setup

### Q: What are the system requirements?
**A:** 
- C++ 11 or higher compiler (g++, clang++, MSVC)
- Minimum 100MB disk space
- Any modern operating system (Windows, Linux, macOS)

### Q: How do I compile the project?
**A:** See [INSTALLATION.md](INSTALLATION.md) for detailed instructions.

### Q: Do I need any external libraries?
**A:** No. The project uses only standard C++ library features.

## Usage Questions

### Q: How do I run the program?
**A:** 
```bash
./twosum
```
Then enter the array and target sum when prompted. See [USAGE.md](USAGE.md) for examples.

### Q: What input formats does it accept?
**A:** The program accepts:
- Space-separated integers for the array
- A single integer for the target sum

### Q: Will the program handle negative numbers?
**A:** Yes. The algorithm works with negative numbers, zero, and positive numbers.

### Q: What are the array size limits?
**A:** 
- Minimum: 2 elements
- Maximum: 10,000 elements (practical limit)
- Large arrays may slow down I/O but algorithm remains O(n)

### Q: How does the program handle invalid input?
**A:** The program validates input and shows error messages for:
- Non-integer values
- Arrays smaller than 2 elements
- Invalid format

See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for solutions.

## Development Questions

### Q: How do I contribute to this project?
**A:** See [CONTRIBUTING.md](CONTRIBUTING.md) for detailed guidelines.

### Q: What code style should I follow?
**A:** Follow the Google C++ Style Guide. Key points:
- 2-space indentation
- snake_case for variables
- CamelCase for classes
- Comprehensive comments

### Q: How should I structure my code?
**A:** 
- Keep functions focused and single-purpose
- Use meaningful variable names
- Add comments explaining the logic
- Maintain consistency with existing code

### Q: Where should I branch from?
**A:** 
- Create feature branches from `test` branch
- Never branch directly from `main`
- Use descriptive branch names: `feature/your-feature-name`

## Troubleshooting

### Q: Program won't compile
**A:** Check:
- C++ compiler version (need C++11 or higher)
- All source files are present
- No syntax errors
See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for more solutions.

### Q: Getting wrong results
**A:** Verify:
- Input format is correct
- Array contains valid integers
- Target is reachable with array elements
- No off-by-one errors in indices

### Q: Program crashes
**A:** 
- Check input isn't empty or malformed
- Ensure array has at least 2 elements
- Verify integer range (32-bit signed int)
See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for detailed debugging steps.

## Performance

### Q: How fast is this solution?
**A:** 
- Time: O(n) - linear time
- Space: O(n) - for hash map
- Handles 10,000 elements in milliseconds

### Q: Can I optimize it further?
**A:** The O(n) solution is optimal for this problem. Further optimizations depend on specific constraints or hardware.

### Q: How does it compare to brute force?
**A:** 
- Brute Force: O(n²) time, O(1) space
- Hash Map: O(n) time, O(n) space
- The hash map approach is 100-1000x faster for Large arrays

## Platform-Specific

### Q: Will this work on Windows?
**A:** Yes. Compile with MSVC, MinGW, or use WSL with g++.

### Q: Can I use this on macOS?
**A:** Yes. Use clang++ or g++ from Homebrew.

### Q: What about Linux?
**A:** Yes. Use g++, clang++, or your system's C++ compiler.
