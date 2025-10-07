// Importing Neccessary Packages //
#include <iostream>
#include <vector>
#include <string>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Declaring Prefix Variable to store prefix //
        string prefix = strs[0];
        // Looping through remaining strings //
        for (int i = 1; i < strs.size(); i++) {
            // While current string does not start with prefix //
            while (strs[i].find(prefix) != 0) {
                // Shrink the prefix by removing last character //
                prefix = prefix.substr(0, prefix.size() - 1);
                // If nothing left, no common prefix //
                if (prefix.empty()) return "";
            }
        }
        // Returning Prefix //
        return prefix;
    }
};

// Main function to pass test case //
int main() {
    Solution solution;
    // Test Case 1 //
    vector<string> t1{"flower","flow","flight"};
    if (solution.longestCommonPrefix(t1) == "fl") {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }
    // Test Case 2 //
    vector<string> t2{"dog","racecar","car"};
    if (solution.longestCommonPrefix(t2) == "") {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }
    return 0;
}