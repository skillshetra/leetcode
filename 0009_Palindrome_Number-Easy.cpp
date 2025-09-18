// Importing Neccessary Packages //
#include <iostream>

// Using standard namespace //
using namespace std;

// Class Solution with function to check if number is pallindrome //
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending with 0 cannot be palindrome //
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        // Looping through number to saved reversed //
        int reversed_half = 0;
        while(x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        // For even-length numbers, reversed_half == x //
        // For odd-length numbers, drop last digit of reversed_half // 
        return (x == reversed_half) || (x == reversed_half / 10);
    }
};

// Main Function to run all Test Cases //
int main() {
    Solution solution;
    if(solution.isPalindrome(121) == true) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }
    if(solution.isPalindrome(-121) == false) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }
    if(solution.isPalindrome(10) == false) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }
    return 0;
}