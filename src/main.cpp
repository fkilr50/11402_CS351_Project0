#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Forward declaration of twoSum function
std::vector<int> twoSum(std::vector<int>& nums, int target);

/**
 * Displays usage instructions to the user.
 */
void PrintUsage() {
  std::cout << "\n=== Two Sum Problem Solver ===\n" << std::endl;
  std::cout << "This program finds two distinct numbers in an array that add up to "
            << "a target sum." << std::endl;
  std::cout << "\nUsage:" << std::endl;
  std::cout << "1. Enter the array size\n"
            << "2. Enter array elements (space-separated integers)\n"
            << "3. Enter the target sum\n" << std::endl;
}

/**
 * Gets array size from user with validation.
 *
 * @return The array size (minimum 2)
 */
int GetArraySize() {
  int size = 0;
  while (true) {
    std::cout << "Enter array size: ";
    if (std::cin >> size && size >= 2) {
      return size;
    }
    std::cout << "Error: Please enter a valid size (minimum 2)\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
}

/**
 * Gets array elements from user with validation.
 *
 * @param size The expected array size
 * @return A vector of integers
 */
std::vector<int> GetArrayElements(int size) {
  std::vector<int> nums;
  std::cout << "Enter array elements (space-separated): ";

  std::cin.ignore();  // Clear newline from previous input
  std::string line;
  std::getline(std::cin, line);

  std::istringstream stream(line);
  int num;

  while (stream >> num) {
    nums.push_back(num);
  }

  // Validate size
  if (nums.size() != size) {
    std::cout << "Error: Expected " << size << " elements, got " << nums.size()
              << ". Please try again.\n";
    return GetArrayElements(size);
  }

  return nums;
}

/**
 * Gets target sum from user.
 *
 * @return The target sum
 */
int GetTargetSum() {
  int target = 0;
  std::cout << "Enter target sum: ";
  std::cin >> target;
  return target;
}

/**
 * Displays the array for user reference.
 *
 * @param nums The array to display
 * @param target The target sum
 */
void DisplayInput(const std::vector<int>& nums, int target) {
  std::cout << "\nArray: [";
  for (int i = 0; i < nums.size(); ++i) {
    if (i > 0) std::cout << ", ";
    std::cout << nums[i];
  }
  std::cout << "]\nTarget: " << target << "\n" << std::endl;
}

/**
 * Displays the solution result.
 *
 * @param result The indices returned by twoSum
 * @param nums The original array
 * @param target The target sum
 */
void DisplayResult(const std::vector<int>& result, const std::vector<int>& nums,
                   int target) {
  if (result.empty()) {
    std::cout << "Result: No solution found.\n"
              << "No two distinct numbers in the array sum to the target.\n";
  } else {
    std::cout << "Result: Indices [" << result[0] << ", " << result[1] << "]\n"
              << "Explanation: nums[" << result[0] << "] + nums[" << result[1]
              << "] = " << nums[result[0]] << " + " << nums[result[1]] << " = "
              << (nums[result[0]] + nums[result[1]]) << "\n";
  }
}

/**
 * Main program entry point.
 *
 * Handles user interaction and calls the twoSum algorithm.
 */
int main() {
  try {
    // Display usage information
    PrintUsage();

    // Get input from user
    int size = GetArraySize();
    std::vector<int> nums = GetArrayElements(size);
    int target = GetTargetSum();

    // Display formatted input
    DisplayInput(nums, target);

    // Solve the problem
    std::vector<int> result = twoSum(nums, target);

    // Display results
    DisplayResult(result, nums, target);

    std::cout << "\n";
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}