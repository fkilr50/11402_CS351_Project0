# Usage Guide

## Running the Program

### Compilation
First, compile the project:

```bash
g++ -o twosum src/main.cpp src/twosum.cpp
```

### Execution

**Linux/macOS:**
```bash
./twosum
```

**Windows:**
```cmd
twosum.exe
```

## Input Format

The program will prompt you for two inputs:

### 1. Array Elements
Enter space-separated integers:
```
Enter array size: 4
Enter array elements (space-separated): 2 7 11 15
```

### 2. Target Sum
Enter a single integer:
```
Enter target sum: 9
```

## Output Format

The program returns indices of two numbers that sum to the target:

```
Result: Indices [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

## Examples

### Example 1: Basic Usage

**Input:**
```
Array size: 4
Array elements: 2 7 11 15
Target sum: 9
```

**Output:**
```
Result: Indices [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

**Explanation:** The numbers at index 0 (2) and index 1 (7) add up to 9.

---

### Example 2: Negative Numbers

**Input:**
```
Array size: 3
Array elements: -1 0 1
Target sum: 0
```

**Output:**
```
Result: Indices [0, 2]
Explanation: nums[0] + nums[2] = -1 + 1 = 0
```

**Explanation:** Works with negative numbers too.

---

### Example 3: Larger Array

**Input:**
```
Array size: 8
Array elements: 3 2 4 6 1 9 8 5
Target sum: 10
```

**Output:**
```
Result: Indices [4, 7]
Explanation: nums[4] + nums[7] = 1 + 9 = 10
```

**Alternative solutions:** [1, 5] (1+9), [2, 3] (4+6), [0, 3] (3+7) etc.
Note: The algorithm returns the first valid pair found.

---

### Example 4: No Solution

**Input:**
```
Array size: 3
Array elements: 1 2 3
Target sum: 10
```

**Output:**
```
No solution found.
No two distinct numbers in the array sum to the target.
```

**Explanation:** No pair of numbers can sum to 10.

---

### Example 5: Duplicate Elements

**Input:**
```
Array size: 4
Array elements: 5 2 5 8
Target sum: 13
```

**Output:**
```
Result: Indices [2, 3]
Explanation: nums[2] + nums[3] = 5 + 8 = 13
```

**Note:** Duplicates are allowed; we just need different indices.

---

## Advanced Usage

### Batch Testing (create test_input.txt)

```
4
2 7 11 15
9
```

Run with input redirection:

**Linux/macOS:**
```bash
./twosum < test_input.txt
```

**Windows:**
```cmd
twosum.exe < test_input.txt
```

### Test Cases to Try

| Test | Input | Expected Output |
|------|-------|------------------|
| Simple | `[2,7,11,15]`, target=9 | `[0,1]` |
| Negative | `[-1,0,1]`, target=0 | `[0,2]` |
| Large numbers | `[1000000,1,999999]`, target=1000000 | `[0,1]` |
| No solution | `[1,2,3]`, target=10 | No solution |
| Min size | `[1,2]`, target=3 | `[0,1]` |
| Duplicates | `[0,0,3,4]`, target=0 | `[0,1]` |

## Common Input Patterns

### Linear Sequence
```
Array: 1 2 3 4 5 6 7 8 9 10
Target: 15
Expected: Multiple solutions like [6,8] (7+8=15)
```

### All Zeros
```
Array: 0 0 0 1 2
Target: 0
Expected: [0,1] (0+0=0)
```

### Negative Array
```
Array: -5 -3 -1 0 2 4
Target: -4
Expected: [-5,1] (-5+1=-4)
```

## Edge Cases

### Minimum Size Array
```
Array: 5 10
Target: 15
Expected: [0,1]
```

### Large Array (performance test)
```bash
# Create array with 10,000 elements
Array: 1 2 3 ... 10000
Target: 19999
Expected: [9998, 9999] (9999+10000=19999)
# Should complete in <1 second
```

### Target Equals Zero
```
Array: -10 0 5 10
Target: 0
Expected: [-10,5] (-10+10=0)
```

## Interpreting Results

### Understanding the Output

```
Result: Indices [2, 5]
Explanation: nums[2] + nums[5] = 4 + 6 = 10
```

- **[2, 5]** = The two indices
- **nums[2]** = Element at index 2
- **nums[5]** = Element at index 5
- **4 + 6 = 10** = The sum equals target

### Multiple Solutions

The algorithm returns the first valid pair found during iteration. If multiple solutions exist, it doesn't find all of them—only the first one encountered.

```
# Example: Array [2,3,4,5,7], Target 9
# Possible solutions: [0,4] (2+7), [1,4] (3+7), [2,3] (4+5) 
# Algorithm returns first found: [0,4]
```

## Tips for Usage

### Valid Input
- ✅ Space-separated integers: `2 7 11 15`
- ✅ Negative numbers: `-5 -3 0 2`
- ✅ Large numbers: `1000000 999999`
- ✅ Zeros: `0 0 0 1`

### Invalid Input  
- ❌ Comma-separated: `2, 7, 11, 15`
- ❌ Non-integers: `2 a 11 15`
- ❌ Too few elements: `5` (needs at least 2)
- ❌ Mixed format: `2, 7 11, 15`

### Debugging Output

If result seems wrong, verify manually:

```cpp
// Manual check:
Array: [2, 7, 11, 15]
Target: 9
Result: [0, 1]

// Verify: nums[0] + nums[1] = 2 + 7 = 9 ✓
```

## Performance Characteristics

**Time Complexity:** O(n) - Single linear pass with O(1) hash lookups

**Array Size → Approximate Time:**
- 100 elements: < 1ms
- 1,000 elements: < 1ms
- 10,000 elements: < 10ms
- 100,000 elements: < 100ms

**Note:** Actual time varies by system and input values.

## Next Steps

- 🔍 Read [ARCHITECTURE.md](ARCHITECTURE.md) to understand the algorithm
- 📚 Check [API_REFERENCE.md](API_REFERENCE.md) for function details
- ❓ See [FAQ.md](FAQ.md) for common questions
- 🐛 Review [TROUBLESHOOTING.md](TROUBLESHOOTING.md) if issues arise
