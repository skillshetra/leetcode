// Importing Neccessary Packages //
#include <iostream>
#include <vector>
#include <algorithm>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort to use the two-pointer technique efficiently //
        sort(nums.begin(), nums.end());
        const int n = (int)nums.size();

        // Helper lambda to compute absolute difference in 64-bit to avoid overflow //
        auto diff = [](long long a, long long b) -> long long {
            long long d = a - b;
            return d >= 0 ? d : -d;
        };

        // Initialize with the sum of the first three //
        int best = nums[0] + nums[1] + nums[2];

        // Iterate each index as the first element of the triplet //
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate anchors to avoid redundant work //
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // minimal possible sum with current i //
            long long minSum = (long long)nums[i] + nums[i + 1] + nums[i + 2];
            if (minSum > target) {
                // If even the smallest sum at this i exceeds target //
                if (diff(minSum, target) < diff(best, target)) best = (int)minSum;
                break;
            }

            // maximal possible sum with current i //
            long long maxSum = (long long)nums[i] + nums[n - 2] + nums[n - 1];
            if (maxSum < target) {
                // If even the largest sum is below target //
                if (diff(maxSum, target) < diff(best, target)) best = (int)maxSum;
                continue;
            }

            // Two-pointer search between i+1 and n-1 //
            int l = i + 1, r = n - 1;
            while (l < r) {
                long long cur = (long long)nums[i] + nums[l] + nums[r];

                // Update best if this sum is closer //
                if (diff(cur, target) < diff(best, target)) best = (int)cur;

                if (cur == target) {
                    // Exact match is the optimal answer //
                    return (int)cur;
                } else if (cur < target) {
                    // Move left pointer rightward, skipping duplicates //
                    int lv = nums[l];
                    while (l < r && nums[l] == lv) ++l;
                } else {
                    // Move right pointer leftward, skipping duplicates //
                    int rv = nums[r];
                    while (l < r && nums[r] == rv) --r;
                }
            }
        }
        return best;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Test Case 1 //
    {
        vector<int> nums = {-1, 2, 1, -4};
        int target = 1;
        int expected = 2;
        int result = sol.threeSumClosest(nums, target);

        if (result == expected) {
            cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
        }
    }
    // Test Case 2 //
    {
        vector<int> nums = {0, 0, 0};
        int target = 1;
        int expected = 0;
        int result = sol.threeSumClosest(nums, target);

        if (result == expected) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    return 0;
}