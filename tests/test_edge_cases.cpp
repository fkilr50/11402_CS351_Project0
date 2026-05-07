#include <vector>
#include <iostream>

// Forward declaration
std::vector<int> twoSum(std::vector<int>& nums, int target);

// External test counter
extern int tests_passed;
extern int tests_failed;
extern int tests_total;

void assert_equal(const std::vector<int>& result, const std::vector<int>& expected, const std::string& test_name);
void assert_true(bool condition, const std::string& test_name);

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
