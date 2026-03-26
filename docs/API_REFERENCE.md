# API Reference

## TwoSum Function

### Overview
The `twoSum()` function solves the Two Sum problem by finding two distinct indices in an array where the elements add up to a specified target value.

### Function Signature

```cpp
std::vector<int> twoSum(std::vector<int>& nums, int target);
```

### Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| `nums` | `std::vector<int>&` | Reference to an array of integers |
| `target` | `int` | The target sum to find |

### Return Value

**Type:** `std::vector<int>`

Returns a vector containing exactly two elements:
- `result[0]`: Index of the first number
- `result[1]`: Index of the second number

Where `nums[result[0]] + nums[result[1]] == target`

### Example Usage

```cpp
std::vector<int> nums = {2, 7, 11, 15};
int target = 9;
std::vector<int> result = twoSum(nums, target);
// result = [0, 1]
```

### Constraints

- Array length: 2 ≤ `nums.size()` ≤ 10⁴
- Valid target requires exactly one solution
- Cannot use the same element twice
- Indices must be distinct (i ≠ j)

### Time Complexity

**O(n)** - Single pass using hash map optimization

### Space Complexity

**O(n)** - For the hash map storage in worst case
