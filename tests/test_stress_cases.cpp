#include <vector>
#include <iostream>
#include <chrono>
#include <climits>

// Forward declaration
std::vector<int> twoSum(std::vector<int>& nums, int target);

// External test counter
extern int tests_passed;
extern int tests_failed;
extern int tests_total;

void assert_equal(const std::vector<int>& result, const std::vector<int>& expected, const std::string& test_name);

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
        int target = 999 + 500; // 1499
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> result = twoSum(nums, target);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        
        if (!result.empty() && result.size() == 2 && 
            nums[result[0]] + nums[result[1]] == target) {
            std::cout << "✓ STRESS-001: 1000 elements - Completed in " << duration.count() << "ms" << std::endl;
            tests_passed++;
        }
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
        
        if (!result.empty() && result.size() == 2 && 
            nums[result[0]] + nums[result[1]] == target) {
            std::cout << "✓ STRESS-002: 10000 elements - Completed in " << duration.count() << "ms" << std::endl;
            tests_passed++;
        }
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
