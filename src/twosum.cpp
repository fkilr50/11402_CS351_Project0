#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // Key: the number in the array, Value: its index
    std::unordered_map<int, int> seen;

    for (int i = 0; i < (int)nums.size(); i++) {
        // Calculate the value we need to find to reach the target
        // Equation: nums[i] + complement = target
        int complement = target - nums[i];

        // Check if the complement has already been encountered
        if (seen.find(complement) != seen.end()) {
            // If found, return the index of the complement and current index
            return {seen[complement], i};
        }

        // Otherwise, store the current number and its index in the map
        seen[nums[i]] = i;
    }

    // Return empty vector if no solution is found (handles EC-007 and EC-008)
    return {};
}