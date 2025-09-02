// Including Neccessary Header Files //
#include <iostream>
#include <stdbool.h>

// Using standard namespace //
using namespace std;

// Solution Class to reverse the number //
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Checking for overflows. //
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

// Main function to run test cases //
int main() {
    Solution solution;
    if (solution.reverse(123) == 321) {
        cout << "\033[32mTest Case 1 Passed.\033[0m\n";
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m\n";
    }
    if (solution.reverse(-123) == -321) {
        cout << "\033[32mTest Case 2 Passed.\033[0m\n";
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m\n";
    }
    if (solution.reverse(120) == 21) {
        cout << "\033[32mTest Case 3 Passed.\033[0m\n";
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m\n";
    }
    return 0;
}