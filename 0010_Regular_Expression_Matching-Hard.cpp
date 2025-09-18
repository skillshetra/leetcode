// Importing Neccessary Packages //
#include <iostream>
#include <vector>
#include <string>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = (int)s.size(), m = (int)p.size();
        // -1 = unknown, 0 = false, 1 = true //
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        auto dfs = [&](auto&& self, int i, int j) -> bool {
            int &cell = memo[i][j];
            if (cell != -1) return cell;

            // If pattern exhausted, match only if string also exhausted //
            if (j == m) return cell = (i == n);

            // Does current char match //
            bool firstMatch = (i < n) && (p[j] == s[i] || p[j] == '.');

            // If next pattern char is '*' skip "x*" (match zero times), or consume one char if current matches and stay on the same pattern //
            if (j + 1 < m && p[j + 1] == '*') {
                bool res = self(self, i, j + 2) || (firstMatch && self(self, i + 1, j));
                return cell = (res ? 1 : 0);
            }

            // Otherwise, consume one char from both if current matches //
            if (firstMatch) {
                bool res = self(self, i + 1, j + 1);
                return cell = (res ? 1 : 0);
            }

            return cell = 0;
        };

        return dfs(dfs, 0, 0);
    }
};

// Main function to pass test case //
int main() {
    Solution solution;
    // Test Case 1 //
    if (solution.isMatch("aa", "a") == false) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }
    // Test Case 2 //
    if (solution.isMatch("aa", "a*") == true) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }
    // Test Case 3 //
    if (solution.isMatch("ab", ".*") == true) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }
    return 0;
}