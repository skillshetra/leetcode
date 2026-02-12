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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        cur.reserve(2 * n);
        function<void(int,int)> dfs = [&](int open, int close) {
            if ((int)cur.size() == 2 * n) {
                ans.push_back(cur);
                return;
            }
            if (open < n) {
                cur.push_back('(');
                dfs(open + 1, close);
                cur.pop_back();
            }
            if (close < open) {
                cur.push_back(')');
                dfs(open, close + 1);
                cur.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    auto normalize = [](vector<string>& v) {
        sort(v.begin(), v.end());
    };
    // Test Case 1 //
    {
        int n = 3;
        vector<string> expected = {"((()))","(()())","(())()","()(())","()()()"};
        auto result = sol.generateParenthesis(n);
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
        int n = 1;
        vector<string> expected = {"()"};
        auto result = sol.generateParenthesis(n);
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
        int n = 2;
        vector<string> expected = {"(())","()()"};
        auto result = sol.generateParenthesis(n);
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