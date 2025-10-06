// Importing Neccessary Packages //
#include <iostream>
#include <string>
#include <unordered_map>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    int romanToInt(string s) {
        // Declaring Hashmap and result variable //
        int result = 0;
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        // Changing Roman Number to Integer //
        for (int i = 0; i < s.size(); i++) {
            int value = mp[s[i]];
            if (i + 1 < s.size() && value < mp[s[i + 1]]) {
                result -= value;
            } else {
                result += value;
            }
        }
        // Returning Result //
        return result;
    }
};

// Main function to pass test case //
int main() {
    // Running Test Cases //
    Solution solution;
    // Test Case 1 //
    if (solution.romanToInt("III") == 3) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }
    // Test Case 2 //
    if (solution.romanToInt("LVIII") == 58) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }
    // Test Case 3 //
    if (solution.romanToInt("MCMXCIV") == 1994) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }
    return 0;
}