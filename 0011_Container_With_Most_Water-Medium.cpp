// Importing Neccessary Packages //
#include <iostream>
#include <vector>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    int maxArea(vector<int>& height) {
        // Declaring Left Right and Max Area //
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate current area //
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h * w;

            // Update maximum area //
            maxArea = max(maxArea, area);

            // Move the pointer pointing to the smaller height //
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

// Main function to pass test case //
int main() {
    Solution solution;
    vector<int> tc1{1,8,6,2,5,4,8,3,7};
    if (solution.maxArea(tc1) == 49)
        cout << "\033[32mTest Case 1 Passed.\033[0m\n";
    else
        cout << "\033[31mTest Case 1 Failed.\033[0m\n";
    vector<int> tc2{1,1};
    if (solution.maxArea(tc2) == 1)
        cout << "\033[32mTest Case 2 Passed.\033[0m\n";
    else
        cout << "\033[31mTest Case 2 Failed.\033[0m\n";
    return 0;
}