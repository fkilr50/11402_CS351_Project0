# Test Plan for Two Sum Problem Solver

## Overview
This document outlines the comprehensive test strategy for the Two Sum algorithm implementation. Tests are organized into four categories covering basic functionality, edge cases, and performance scenarios.

## Test Categories

### 1. Simple Cases (Basic Functionality)
These tests verify that the algorithm works correctly with typical, straightforward inputs.

| Test ID | Input | Target | Expected Output | Description |
|---------|-------|--------|-----------------|-------------|
| SC-001 | [2, 7, 11, 15] | 9 | [0, 1] | Basic case from problem statement |
| SC-002 | [3, 2, 4] | 6 | [1, 2] | Three elements, middle match |
| SC-003 | [1, 2] | 3 | [0, 1] | Minimum valid array (2 elements) |
| SC-004 | [5, 1, 8, 10] | 15 | [2, 3] | Two elements at end |
| SC-005 | [100, 50, 25] | 150 | [0, 1] | Larger numbers |

### 2. Edge Cases (Boundary & Special Conditions)
These tests verify correct behavior with boundary values, special conditions, and potential error scenarios.

| Test ID | Input | Target | Expected Output | Description |
|---------|-------|--------|-----------------|-------------|
| EC-001 | [-1, -2, -3, -5] | -8 | [2, 3] | All negative numbers |
| EC-002 | [0, 0] | 0 | [0, 1] | Zero as target with identical zeros |
| EC-003 | [-5, 0, 5, 10] | 0 | [0, 1] or [1, 2] | Mix of negative, zero, positive |
| EC-004 | [1, 1, 1, 1] | 2 | [0, 1] | Duplicate values |
| EC-005 | [-1, 0, 1, 2, 3] | 2 | [0, 4] or [1, 3] | Negative and positive with zero |
| EC-006 | [INT_MAX, 1] | INT_MAX + 1 | [0, 1] | Integer overflow risk |
| EC-007 | [INT_MIN, 0] | INT_MIN | [0, 1] | Minimum integer value |
| EC-008 | [5, 4, 3, 2, 1] | 7 | [0, 3] | Reverse sorted array |
| EC-009 | [] | 0 | [] | Empty array (no solution) |
| EC-010 | [1] | 1 | [] | Single element (cannot form pair) |

### 3. Single Amount Cases (Specific Sum Scenarios)
These tests verify the algorithm's ability to find pairs that sum to specific target values with various input characteristics.

| Test ID | Input | Target | Expected Output | Description |
|---------|-------|--------|-----------------|-------------|
| SA-001 | [1, 2, 3, 4, 5] | 5 | [0, 4] | Target is 5 with multiple options |
| SA-002 | [10, 20, 30, 40] | 50 | [1, 2] | Target is 50 |
| SA-003 | [-10, -5, 0, 5, 10] | 0 | [1, 3] or [0, 4] | Target is 0 (zero sum) |
| SA-004 | [1, 1, 1, 1, 1] | 2 | [0, 1] | Target with all identical elements |
| SA-005 | [100, 200, 300, 400, 500] | 600 | [1, 3] | Target with large numbers |

### 4. Stress Cases (Performance & Scale)
These tests verify the algorithm's performance with large inputs and high complexity scenarios.

| Test ID | Input Size | Target | Description |
|---------|-----------|--------|-------------|
| STRESS-001 | 1,000 elements | Random target | Large array with random integers |
| STRESS-002 | 10,000 elements | Random target | Very large array performance test |
| STRESS-003 | 1,000 elements (all duplicates) | 2x value | Worst-case hash collision scenario |
| STRESS-004 | 5,000 elements (sorted) | Max+1 | Large sorted array, no solution |
| STRESS-005 | 10,000 elements (range: INT_MIN to INT_MAX) | 0 | Extreme value range test |

## Test Execution Strategy

### Environment
- **Language:** C++20
- **Build System:** CMake
- **Test Framework:** Custom C++ test executable using `assert()` and manual verification
- **CI/CD:** GitHub Actions

### Build Requirements
```bash
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_STANDARD=20 \
  -DCMAKE_CXX_STANDARD_REQUIRED=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

### Success Criteria
- ✅ All simple cases pass
- ✅ All edge cases pass without crashes or exceptions
- ✅ All single amount cases produce correct indices
- ✅ Stress cases complete within reasonable time (< 5 seconds each)
- ✅ No memory leaks detected

## Testing Implementation

### Test File Location
`src/test_twosum.cpp`

### Test Organization Structure
```cpp
// Simple Cases
TEST(TwoSum, SimpleCase_BasicExample)
TEST(TwoSum, SimpleCase_ThreeElements)
TEST(TwoSum, SimpleCase_MinimumArray)

// Edge Cases
TEST(TwoSum, EdgeCase_AllNegative)
TEST(TwoSum, EdgeCase_ZeroTarget)
TEST(TwoSum, EdgeCase_Duplicates)

// Single Amount
TEST(TwoSum, SingleAmount_Target5)
TEST(TwoSum, SingleAmount_LargeNumbers)

// Stress Cases
TEST(TwoSum, Stress_LargeArray1000)
TEST(TwoSum, Stress_VeryLargeArray10000)
```

## CI/CD Integration

### GitHub Actions Workflow
- Trigger on: `push` and `pull_request` events
- Runs on: Ubuntu Latest
- Steps:
  1. Checkout code
  2. Install C++ compiler and CMake
  3. Configure with C++20
  4. Build project
  5. Run tests
  6. Report results

See `.github/workflows/ci.yml` for implementation details.

## Coverage Goals

| Category | Target Coverage | Current Status |
|----------|-----------------|-----------------|
| Simple Cases | 100% | ✓ |
| Edge Cases | 100% | ✓ |
| Single Amount | 100% | ✓ |
| Stress Cases | 80%+ | ✓ |

## Notes

- Tests should be isolated and not dependent on execution order
- Each test case should have a clear assertion message
- Stress tests will help verify algorithm efficiency (O(n) time complexity)
- Edge cases focus on boundary values and special conditions
- All tests must pass before merging to main branch
