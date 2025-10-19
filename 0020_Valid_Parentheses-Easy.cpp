// Importing Neccessary Packages //
#include <iostream>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    bool isValid(string s) {
        // use string as a stack //
        string st;
        st.reserve(s.size());
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push_back(c);
            } else {
                if (st.empty()) return false;
                char o = st.back();
                st.pop_back();
                if ((c == ')' && o != '(') ||
                    (c == ']' && o != '[') ||
                    (c == '}' && o != '{')) return false;
            }
        }
        return st.empty();
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Test Case 1 //
    {
        string s = "()";
        bool expected = true;
        if (sol.isValid(s) == expected) {
            cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
        }
    }
    // Test Case 2 //
    {
        string s = "()[]{}";
        bool expected = true;
        if (sol.isValid(s) == expected) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    // Test Case 3 //
    {
        string s = "(]";
        bool expected = false;
        if (sol.isValid(s) == expected) {
            cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
        }
    }
    // Test Case 4 //
    {
        string s = "([])";
        bool expected = true;
        if (sol.isValid(s) == expected) {
            cout << "\033[32mTest Case 4 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 4 Failed.\033[0m" << endl;
        }
    }
    // Test Case 5 //
    {
        string s = "([)]";
        bool expected = false;
        if (sol.isValid(s) == expected) {
            cout << "\033[32mTest Case 5 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 5 Failed.\033[0m" << endl;
        }
    }
    return 0;
}