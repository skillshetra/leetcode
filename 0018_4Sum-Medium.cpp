// Importing Neccessary Packages //
#include <iostream>
#include <vector>
#include <algorithm>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        const int n = (int)nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        auto add = [&](int a, int b, int c, int d) {
            res.push_back({a, b, c, d});
        };
        for (int i = 0; i < n - 3; ++i) {
            // skip duplicates for i //
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // Prune by minimal and maximal possible sums with fixed i //
            long long min1 = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            // further i will only increase //
            if (min1 > (long long)target) break;
            long long max1 = (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            // need larger i //
            if (max1 < (long long)target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                // Further pruning with fixed //
                long long min2 = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (min2 > (long long)target) break;
                long long max2 = (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (max2 < (long long)target) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == (long long)target) {
                        add(nums[i], nums[j], nums[l], nums[r]);
                        // advance l and r skipping duplicates //
                        int lv = nums[l], rv = nums[r];
                        while (l < r && nums[l] == lv) ++l;
                        while (l < r && nums[r] == rv) --r;
                    } else if (sum < (long long)target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return res;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Helper: normalize for comparison
    auto normalize = [](vector<vector<int>> &v) {
        for (auto &x : v) sort(x.begin(), x.end());
        sort(v.begin(), v.end());
    };
    // Test Case 1 //
    {
        vector<int> nums = {1,0,-1,0,-2,2};
        int target = 0;
        vector<vector<int>> expected = {{-2,-1,1,2}, {-2,0,0,2}, {-1,0,0,1}};
        auto result = sol.fourSum(nums, target);
        normalize(expected);
        normalize(result);
        if (result == expected) {
            cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
        }
    }
    // Test Case 2 //
    {
        vector<int> nums = {2,2,2,2,2};
        int target = 8;
        vector<vector<int>> expected = {{2,2,2,2}};
        auto result = sol.fourSum(nums, target);
        normalize(expected);
        normalize(result);
        if (result == expected) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    // Test Case 3 //
    {
        vector<int> nums = {1,2,3};
        int target = 100;
        vector<vector<int>> expected = {};
        auto result = sol.fourSum(nums, target);
        normalize(expected);
        normalize(result);
        if (result == expected) {
            cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
        }
    }
    return 0;
}