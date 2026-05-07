#include <vector>
#include <iostream>
#include <climits>

// Forward declarations
std::vector<int> twoSum(std::vector<int>& nums, int target);
void test_simple_cases();
void test_edge_cases();
void test_single_amount_cases();
void test_stress_cases();

// Global test counters
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
