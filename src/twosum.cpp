#include <vector>
#include <unordered_map>

/**
 * Solves the Two Sum problem efficiently using a hash map approach.
 *
 * Given an array of integers and a target sum, finds two distinct indices
 * where the elements add up to the target value.
 *
 * @param nums Reference to a vector of integers
 * @param target The target sum to find
 * @return A vector containing two indices [i, j] where nums[i] + nums[j] == target
 *         Returns an empty vector if no solution exists
 *
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(n) - Hash map storage in worst case
 */
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  // Hash map to store number -> index mapping
  std::unordered_map<int, int> seen;

  // Iterate through array once
  for (int i = 0; i < nums.size(); ++i) {
    // Calculate the complement needed to reach target
    int complement = target - nums[i];

    // Check if complement exists in hash map (O(1) lookup)
    if (seen.find(complement) != seen.end()) {
      // Found the pair! Return indices
      return {seen[complement], i};
    }

    // Store current number and its index for future lookups
    seen[nums[i]] = i;
  }

  // No solution found
  return {};
}