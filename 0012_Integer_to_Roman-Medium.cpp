// Importing Neccessary Packages //
#include <iostream>
#include <string>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    string intToRoman(int num) {
        // Initialising result and values and symbols //
        string result = "";
        int values[]   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        // Converting Integer to Roman //
        for (int i = 0; i < 13 && num > 0; i++) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }
        // Return Result //
        return result;
    }
};

// Main function to pass test case //
int main() {
    Solution solution;
    // Test Case 1 //
    if (solution.intToRoman(3749) == "MMMDCCXLIX") {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }
    // Test Case 2 //
    if (solution.intToRoman(58) == "LVIII") {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }
    // Test Case 3 //
    if (solution.intToRoman(1994) == "MCMXCIV") {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }
    return 0;
}