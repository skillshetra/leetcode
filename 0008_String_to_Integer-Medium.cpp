// Importing Neccessary Packages //
#include <iostream>

using namespace std;

// Class Solution to generate number from string //
class Solution {
public:
    int myAtoi(string s) {
        // Basic Variables for looping and saving number with sign //
        int i = 0, n = s.size();
        long long num = 0;
        int sign = 1;

        // Skip leading whitespaces //
        while (i < n && s[i] == ' ') i++;
        // 2. Handle optional sign //
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Read digits //
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            num = num * 10 + digit;

            // 4. Handle overflow (clamp to INT_MAX / INT_MIN)
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(num * sign);
    }
};

// Main Function to run Testcases //
int main() {
    Solution solution;
    if (solution.myAtoi("42") == 42) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }
    if (solution.myAtoi(" -042") == -42) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }
    if (solution.myAtoi("1337c0d3") == 1337) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }
    if (solution.myAtoi("0-1") == 0) {
        cout << "\033[32mTest Case 4 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 4 Failed.\033[0m" << endl;
    }
    if (solution.myAtoi("words and 987") == 0) {
        cout << "\033[32mTest Case 5 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 5 Failed.\033[0m" << endl;
    }
    return 0;
}