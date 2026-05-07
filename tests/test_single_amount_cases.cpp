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
// SINGLE AMOUNT CASES - Specific Sum Scenarios
// ============================================================================

void test_single_amount_cases() {
    std::cout << "\n=== SINGLE AMOUNT CASES ===" << std::endl;
    
    {
        // SA-001: Target is 5
        std::vector<int> nums = {1, 2, 3, 4, 5};
        std::vector<int> result = twoSum(nums, 5);
        assert_equal(result, {1, 2}, "SA-001: Target=5 [1,2,3,4,5]");
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
