// Importing Neccessary Packages //
#include <iostream>
#include <unordered_map>
#include <vector>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Create a hash map to store the value and its corresponding index //
        unordered_map<int, int> map;

        // Loop through each element in the input vector //
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement that would sum with nums[i] to reach the target //
            int complement = target - nums[i];

            // Check if the complement exists in the map //
            if (map.find(complement) != map.end()) {
                // If found, return the indices of the complement and current number //
                return {map[complement], i};
            }

            // Store the current number and its index in the map //
            // This allows us to find it later as a complement if needed //
            map[nums[i]] = i;
        }

        // If no solution is found (though the problem guarantees one), return an empty vector //
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
