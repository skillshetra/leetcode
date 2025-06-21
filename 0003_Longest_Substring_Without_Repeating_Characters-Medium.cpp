// Importing Neccessary Packages //
#include <iostream>
#include <unordered_map>
#include <string>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Faster alternative to unordered_map<char, int>
        int lastSeen[128] = {0};

        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            char currentChar = s[right];
            // Update left to max of current left or last seen index + 1 //
            left = max(left, lastSeen[currentChar]);

            // Update maxLen
            maxLen = max(maxLen, right - left + 1);

            // Store index + 1 (so default 0 can work for unseen characters) //
            lastSeen[currentChar] = right + 1;
        }

        return maxLen;
    }
};

// Main function to pass test case //
int main() {
    // Running Test Cases //
    Solution *solution = new Solution();
    // Test Case 1 //
    if (solution->lengthOfLongestSubstring("abcabcbb") == 3) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }

    // Test Case 2 //
    if (solution->lengthOfLongestSubstring("bbbbb") == 1) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }

    // Test Case 3 //
    if (solution->lengthOfLongestSubstring("pwwkew") == 3) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }
    delete solution;
    return 0;
}