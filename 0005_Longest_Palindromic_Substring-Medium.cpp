// Importing Neccessary Packages //
#include <iostream>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    string longestPalindrome(string s) {
        // A string of length 0 or 1 is always a palindrome //
        int n = s.length();
        if (n < 2) return s;
        // Start index of the longest palindrome found //
        int start = 0;
        // Length of the longest palindrome found //
        int maxLen = 1;

        // Iterate through each character as a potential center //
        for (int i = 0; i < n; ++i) {

            // -------- Check for odd-length palindromes -------- //
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                // Update start index of longest palindrome and Update max length //
                if (len > maxLen) {
                    start = l;
                    maxLen = len;
                }
                // Expand outward //
                --l; ++r;
            }

            // -------- Check for even-length palindromes -------- //
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > maxLen) {
                    start = l;
                    maxLen = len;
                }
                --l; ++r;
            }
        }

        // Return the longest palindrome substring using a fast constructor //
        return string(s.begin() + start, s.begin() + start + maxLen);
    }
};


// Main function to pass test case //
int main() {
    // Running all TestCases //
    Solution *solution = new Solution();

    // Test Case 1 //
    if (solution->longestPalindrome("babad") == "bab") {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }

    // Test Case 2 //
    if (solution->longestPalindrome("cbbd") == "bb") {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }

    return 0;
}