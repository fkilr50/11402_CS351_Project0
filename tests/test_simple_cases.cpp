#include <vector>
#include <iostream>

// Forward declaration
std::vector<int> twoSum(std::vector<int>& nums, int target);

// External test counter
extern int tests_passed;
extern int tests_failed;
extern int tests_total;

void assert_equal(const std::vector<int>& result, const std::vector<int>& expected, const std::string& test_name);

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
