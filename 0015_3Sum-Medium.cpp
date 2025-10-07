// Importing Neccessary Packages //
#include <iostream>
#include <vector>
#include <algorithm>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;  
        // Sort the array to make duplicate handling and two-pointer search easier //
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Step 2: Fix one number at a time //
        for (int i = 0; i < n; ++i) {
            // Skip duplicate values for nums[i] to avoid duplicate triplets //
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // The other two numbers must sum to -nums[i] //
            int target = -nums[i];  
            int l = i + 1;
            int r = n - 1;

            // Step 3: Use two-pointer technique to find pairs that sum to target //
            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == target) {
                    // Found a valid triplet //
                    res.push_back({nums[i], nums[l], nums[r]});

                    // Move both pointers but skip over duplicates //
                    int leftVal = nums[l], rightVal = nums[r];
                    while (l < r && nums[l] == leftVal) ++l;
                    while (l < r && nums[r] == rightVal) --r;

                } else if (sum < target) {
                    // If sum is too small, move left pointer to increase sum //
                    ++l;
                } else {
                    // If sum is too large, move right pointer to decrease sum //
                    --r;
                }
            }
        }
        // Return all unique triplets //
        return res;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Test Case 1 //
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
        auto result = sol.threeSum(nums);
        // Normalize order for comparison
        for (auto &v : result) sort(v.begin(), v.end());
        for (auto &v : expected) sort(v.begin(), v.end());
        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());
        if (result == expected) {
            cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
        }
    }
    // Test Case 2 //
    {
        vector<int> nums = {0, 1, 1};
        vector<vector<int>> expected = {};
        auto result = sol.threeSum(nums);
        if (result == expected) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    // Test Case 3 //
    {
        vector<int> nums = {0, 0, 0};
        vector<vector<int>> expected = {{0, 0, 0}};
        auto result = sol.threeSum(nums);
        if (result == expected) {
            cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
        }
    }
    return 0;
}