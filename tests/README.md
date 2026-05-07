# Tests Folder Structure

## Organization

The `tests/` folder contains modular C++ test files organized by test category. Each file contains tests for a specific scenario type.

```
tests/
├── README.md                          # This file
├── test_main.cpp                      # Main test runner & utilities
├── test_simple_cases.cpp              # Simple/Basic functionality tests
├── test_edge_cases.cpp                # Edge cases & boundary conditions
├── test_single_amount_cases.cpp       # Single sum scenarios
└── test_stress_cases.cpp              # Performance & scale tests
```

## Test Files Description

### test_main.cpp
- Entry point for the test suite
- Global test counters: `tests_passed`, `tests_failed`, `tests_total`
- Assertion utilities: `assert_equal()`, `assert_true()`
- Main function that orchestrates all test suites
- Displays formatted test summary with pass rate

### test_simple_cases.cpp
**Simple Cases (SC)** - 5 tests
- Basic functionality verification
- Straightforward inputs with known outputs
- Tests: SC-001 to SC-005

### test_edge_cases.cpp
**Edge Cases (EC)** - 8 tests
- Boundary values and special conditions
- All negative numbers, zeros, duplicates
- No solution scenarios
- Tests: EC-001 to EC-008

### test_single_amount_cases.cpp
**Single Amount (SA)** - 5 tests
- Specific sum scenarios
- Various input characteristics
- Large numbers, zero sums
- Tests: SA-001 to SA-005

### test_stress_cases.cpp
**Stress Cases (STRESS)** - 5 tests
- Performance and scalability
- Large arrays (1K, 10K elements)
- Performance timing measurements
- Tests: STRESS-001 to STRESS-005

## Total Test Count

**23 comprehensive tests** across all 4 categories

## Building the Tests

### With CMake
```bash
cd build
cmake .. -DCMAKE_CXX_STANDARD=20
cmake --build .
```

### Running Tests
```bash
# Using CTest
ctest --output-on-failure -V

# Or directly
./two_sum_tests
```

## Test Output Example

```
╔════════════════════════════════════════════════════════════╗
║   Two Sum Algorithm - Comprehensive Test Suite             ║
╚════════════════════════════════════════════════════════════╝

=== SIMPLE CASES ===
✓ PASS: SC-001: Basic example [2,7,11,15] target=9
✓ PASS: SC-002: Three elements [3,2,4] target=6
...

=== EDGE CASES ===
✓ PASS: EC-001: All negative [-1,-2,-3,-5] target=-8
...

=== SINGLE AMOUNT CASES ===
✓ PASS: SA-001: Target=5 [1,2,3,4,5]
...

=== STRESS CASES ===
✓ STRESS-001: 1000 elements - Completed in 2ms
✓ STRESS-002: 10000 elements - Completed in 15ms
...

╔════════════════════════════════════════════════════════════╗
║                       TEST SUMMARY                          ║
╚════════════════════════════════════════════════════════════╝
Total Tests:  23
Passed:       23 ✓
Failed:       0 ✗
Success Rate: 100%
```

## Adding New Tests

1. Create a new file: `tests/test_new_category.cpp`
2. Define test function: `void test_new_category()`
3. Add forward declaration in `test_main.cpp`
4. Call function from `main()`
5. Update `CMakeLists.txt` to include new file

### Example
```cpp
// tests/test_new_category.cpp
void test_new_category() {
    std::cout << "\n=== NEW CATEGORY ===" << std::endl;
    
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> result = twoSum(nums, 5);
    assert_equal(result, {1, 2}, "Test description");
}
```

## Compilation

The test suite compiles with:
- C++20 standard
- `-Wall -Wextra -Wpedantic` compiler flags
- Linked with `src/twosum.cpp`

## CI/CD Integration

GitHub Actions automatically:
1. Checks out code
2. Installs dependencies
3. Builds all tests from `tests/` folder
4. Runs complete test suite
5. Reports pass/fail status

See `.github/workflows/ci.yml` for details.
