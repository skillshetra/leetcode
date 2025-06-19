// Importing Neccessary Packages //
#include <iostream>
#include <unordered_map>
#include <vector>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
    // Public Class twoSum for solution//
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            // Create a hash map to store each number's value and its index as we iterate //
            unordered_map<int, int> map;
            // Loop through the input vector 'nums' //
            for (int i = 0; i < nums.size(); i++) {
                // Calculate the complement: the number we need to find //
                int complement = target - nums[i];
                // Check if the complement exists in the map //
                if (map.find(complement) != map.end()) {
                    // If it does, we have found the two numbers that add up to target //
                    // Return their indices: index of the complement and current index //
                    return {map[complement], i};
                }
                // If not found, store the current number and its index in the map //
                // This will help future elements check for their complement //
                map[nums[i]] = i;
            }
            // If the loop completes without returning, no valid pair was found //
            // (According to problem constraints, this line is rarely reached) //
            return {};
        }
};

// Main function to pass test case //
int main() {
    // Running Test Cases //
    vector<int> nums = {2, 7, 11, 15};
    Solution *solution = new Solution();
    vector<int> result_1 = solution->twoSum(nums, 9);
    nums = {3, 2, 4};
    vector<int> result_2 = solution->twoSum(nums, 6);
    nums = {3, 3};
    vector<int> result_3 = solution->twoSum(nums, 6);
    delete solution;

    // Test Case 1 //
    if (result_1 == vector<int>{0, 1}) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }

    // Test Case 2 //
    if (result_2 == vector<int>{1, 2}) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }

    // Test Case 3 //
    if (result_3 == vector<int>{0, 1}) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }

    return 0;
}