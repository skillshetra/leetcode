// Importing Neccessary Packages //
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // If no digits, return empty result as per problem statement //
        if (digits.empty()) return {};
        // Mapping from digit to corresponding letters //
        static const vector<string> map = {
            "",    "",    "abc", "def", "ghi",
            "jkl", "mno", "pqrs","tuv","wxyz"
        };
        vector<string> result;
        string cur;
        cur.reserve(digits.size());
        // Backtracking helper (lambda) to build combinations //
        function<void(int)> dfs = [&](int idx) {
            // If we've placed letters for all digits, save the combination //
            if (idx == (int)digits.size()) {
                result.push_back(cur);
                return;
            }
            // Get letters for current digit //
            const string& letters = map[digits[idx] - '0'];
            for (char c : letters) {
                cur.push_back(c);
                dfs(idx + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Test Case 1 //
    {
        string digits = "23";
        vector<string> expected = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
        auto result = sol.letterCombinations(digits);
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
        string digits = "";
        vector<string> expected = {};
        auto result = sol.letterCombinations(digits);

        if (result == expected) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    // Test Case 3 //
    {
        string digits = "2";
        vector<string> expected = {"a","b","c"};
        auto result = sol.letterCombinations(digits);
        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());

        if (result == expected) {
            cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
        }
    }
    return 0;
}