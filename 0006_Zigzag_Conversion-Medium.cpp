// Importing Neccessary Packages //
#include <iostream>
#include <vector>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if only one row or string is too short, return as is //
        if (numRows == 1 || numRows >= s.length()) return s;

        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;

        // Traverse each character in the input string //
        for (char c : s) {
            rows[currRow] += c;
            // Change direction if we’re at the top or bottom //
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;
            // Move up or down
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single result string //
        string result;
        for (const string& row : rows)
            result += row;

        return result;
    }
};


// Main function to pass test case //
int main() {
    // Running all TestCases //
    Solution *solution = new Solution();

    // Test Case 1 //
    if (solution->convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR") {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }

    // Test Case 2 //
    if (solution->convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI") {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }

    return 0;
}