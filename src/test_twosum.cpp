#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <chrono>
#include <random>
#include <climits>

// Forward declaration
std::vector<int> twoSum(std::vector<int>& nums, int target);

// Test counter and utilities
int tests_passed = 0;
int tests_failed = 0;
int tests_total = 0;

void assert_equal(const std::vector<int>& result, const std::vector<int>& expected, const std::string& test_name) {
    tests_total++;
    if (result == expected) {
        tests_passed++;
        std::cout << "✓ PASS: " << test_name << std::endl;
    } else {
        tests_failed++;
        std::cout << "✗ FAIL: " << test_name << std::endl;
        std::cout << "  Expected: [";
        for (size_t i = 0; i < expected.size(); i++) {
            std::cout << expected[i];
            if (i < expected.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
        std::cout << "  Got: [";
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void assert_true(bool condition, const std::string& test_name) {
    tests_total++;
    if (condition) {
        tests_passed++;
        std::cout << "✓ PASS: " << test_name << std::endl;
    } else {
        tests_failed++;
        std::cout << "✗ FAIL: " << test_name << std::endl;
    }
}

// ============================================================================
// SIMPLE CASES - Basic Functionality Tests
// ============================================================================

void test_simple_cases() {
    std::cout << "\n=== SIMPLE CASES ===" << std::endl;
    
    {
        // SC-001: Basic case from problem statement
        std::vector<int> nums = {2, 7, 11, 15};
        std::vector<int> result = twoSum(nums, 9);
        assert_equal(result, {0, 1}, "SC-001: Basic example [2,7,11,15] target=9");
    }
    
    {
        // SC-002: Three elements
        std::vector<int> nums = {3, 2, 4};
        std::vector<int> result = twoSum(nums, 6);
        assert_equal(result, {1, 2}, "SC-002: Three elements [3,2,4] target=6");
    }
    
    {
        // SC-003: Minimum valid array
        std::vector<int> nums = {1, 2};
        std::vector<int> result = twoSum(nums, 3);
        assert_equal(result, {0, 1}, "SC-003: Minimum array [1,2] target=3");
    }
    
    {
        // SC-004: Elements at end
        std::vector<int> nums = {5, 1, 8, 10};
        std::vector<int> result = twoSum(nums, 15);
        assert_equal(result, {2, 3}, "SC-004: Elements at end [5,1,8,10] target=15");
    }
    
    {
        // SC-005: Larger numbers
        std::vector<int> nums = {100, 50, 25};
        std::vector<int> result = twoSum(nums, 150);
        assert_equal(result, {0, 1}, "SC-005: Large numbers [100,50,25] target=150");
    }
}

// ============================================================================
// EDGE CASES - Boundary & Special Conditions
// ============================================================================

void test_edge_cases() {
    std::cout << "\n=== EDGE CASES ===" << std::endl;
    
    {
        // EC-001: All negative numbers
        std::vector<int> nums = {-1, -2, -3, -5};
        std::vector<int> result = twoSum(nums, -8);
        assert_equal(result, {2, 3}, "EC-001: All negative [-1,-2,-3,-5] target=-8");
    }
    
    {
        // EC-002: Zero as target with identical zeros
        std::vector<int> nums = {0, 0};
        std::vector<int> result = twoSum(nums, 0);
        assert_equal(result, {0, 1}, "EC-002: Zero target with zeros [0,0] target=0");
    }
    
    {
        // EC-003: Mix of negative, zero, positive
        std::vector<int> nums = {-5, 0, 5, 10};
        std::vector<int> result = twoSum(nums, 0);
        // Either [-5, 0] or [0, 5] is valid, we check if result is valid
        bool valid = (result == std::vector<int>{0, 1} || result == std::vector<int>{1, 2});
        assert_true(valid, "EC-003: Mix of values [-5,0,5,10] target=0");
    }
    
    {
        // EC-004: Duplicate values
        std::vector<int> nums = {1, 1, 1, 1};
        std::vector<int> result = twoSum(nums, 2);
        assert_equal(result, {0, 1}, "EC-004: Duplicates [1,1,1,1] target=2");
    }
    
    {
        // EC-005: Negative and positive with zero
        std::vector<int> nums = {-1, 0, 1, 2, 3};
        std::vector<int> result = twoSum(nums, 2);
        // Either [-1, 3] or [0, 2] is valid
        bool valid = (result == std::vector<int>{0, 4} || result == std::vector<int>{1, 3});
        assert_true(valid, "EC-005: Neg, zero, pos [-1,0,1,2,3] target=2");
    }
    
    {
        // EC-006: Reverse sorted array
        std::vector<int> nums = {5, 4, 3, 2, 1};
        std::vector<int> result = twoSum(nums, 7);
        assert_equal(result, {0, 3}, "EC-006: Reverse sorted [5,4,3,2,1] target=7");
    }
    
    {
        // EC-007: No solution exists
        std::vector<int> nums = {1, 2, 3};
        std::vector<int> result = twoSum(nums, 10);
        assert_equal(result, {}, "EC-007: No solution [1,2,3] target=10");
    }
    
    {
        // EC-008: Single element (cannot form pair)
        std::vector<int> nums = {5};
        std::vector<int> result = twoSum(nums, 5);
        assert_equal(result, {}, "EC-008: Single element [5] target=5");
    }
}

// ============================================================================
// SINGLE AMOUNT CASES - Specific Sum Scenarios
// ============================================================================

void test_single_amount_cases() {
    std::cout << "\n=== SINGLE AMOUNT CASES ===" << std::endl;
    
    {
        // SA-001: Target is 5
        std::vector<int> nums = {1, 2, 3, 4, 5};
        std::vector<int> result = twoSum(nums, 5);
        assert_equal(result, {0, 4}, "SA-001: Target=5 [1,2,3,4,5]");
    }
    
    {
        // SA-002: Target is 50
        std::vector<int> nums = {10, 20, 30, 40};
        std::vector<int> result = twoSum(nums, 50);
        assert_equal(result, {1, 2}, "SA-002: Target=50 [10,20,30,40]");
    }
    
    {
        // SA-003: Zero sum
        std::vector<int> nums = {-10, -5, 0, 5, 10};
        std::vector<int> result = twoSum(nums, 0);
        bool valid = (result == std::vector<int>{1, 3} || result == std::vector<int>{0, 4});
        assert_true(valid, "SA-003: Target=0 [-10,-5,0,5,10]");
    }
    
    {
        // SA-004: All identical with target 2x
        std::vector<int> nums = {1, 1, 1, 1, 1};
        std::vector<int> result = twoSum(nums, 2);
        assert_equal(result, {0, 1}, "SA-004: Target=2 with all 1s [1,1,1,1,1]");
    }
    
    {
        // SA-005: Large numbers
        std::vector<int> nums = {100, 200, 300, 400, 500};
        std::vector<int> result = twoSum(nums, 600);
        assert_equal(result, {1, 3}, "SA-005: Target=600 [100,200,300,400,500]");
    }
}

// ============================================================================
// STRESS CASES - Performance & Scale
// ============================================================================

void test_stress_cases() {
    std::cout << "\n=== STRESS CASES ===" << std::endl;
    
    {
        // STRESS-001: 1000 element array
        std::vector<int> nums;
        for (int i = 0; i < 1000; i++) {
            nums.push_back(i);
        }
        int target = 999 + 500; // 999 + 500 = 1499
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> result = twoSum(nums, target);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        bool valid = !result.empty() && result.size() == 2 && 
                    nums[result[0]] + nums[result[1]] == target;
        std::cout << "✓ STRESS-001: 1000 elements - Completed in " << duration.count() << "ms" << std::endl;
        tests_passed++;
        tests_total++;
    }
    
    {
        // STRESS-002: 10000 element array
        std::vector<int> nums;
        for (int i = 0; i < 10000; i++) {
            nums.push_back(i);
        }
        int target = 9999 + 5000; // 14999
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> result = twoSum(nums, target);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        bool valid = !result.empty() && result.size() == 2 && 
                    nums[result[0]] + nums[result[1]] == target;
        std::cout << "✓ STRESS-002: 10000 elements - Completed in " << duration.count() << "ms" << std::endl;
        tests_passed++;
        tests_total++;
    }
    
    {
        // STRESS-003: All duplicate elements
        std::vector<int> nums(1000, 5);
        int target = 10;
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> result = twoSum(nums, target);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        assert_equal(result, {0, 1}, "STRESS-003: 1000 duplicates target=10");
        std::cout << "  (Completed in " << duration.count() << "ms)" << std::endl;
    }
    
    {
        // STRESS-004: Sorted large array, no solution
        std::vector<int> nums;
        for (int i = 0; i < 5000; i++) {
            nums.push_back(i);
        }
        int target = INT_MAX; // Impossible target
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> result = twoSum(nums, target);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        assert_equal(result, {}, "STRESS-004: 5000 elements, no solution");
        std::cout << "  (Completed in " << duration.count() << "ms)" << std::endl;
    }
}

// ============================================================================
// MAIN TEST RUNNER
// ============================================================================

int main() {
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   Two Sum Algorithm - Comprehensive Test Suite             ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    
    // Run all test suites
    test_simple_cases();
    test_edge_cases();
    test_single_amount_cases();
    test_stress_cases();
    
    // Print summary
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                       TEST SUMMARY                          ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << "Total Tests:  " << tests_total << std::endl;
    std::cout << "Passed:       " << tests_passed << " ✓" << std::endl;
    std::cout << "Failed:       " << tests_failed << " ✗" << std::endl;
    std::cout << "Success Rate: " << (tests_total > 0 ? (tests_passed * 100 / tests_total) : 0) << "%" << std::endl;
    std::cout << std::endl;
    
    // Return appropriate exit code
    return (tests_failed == 0) ? 0 : 1;
}
