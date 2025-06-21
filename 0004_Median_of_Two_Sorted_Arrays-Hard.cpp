// Importing Neccessary Packages //
#include <iostream>
#include <climits>
#include <vector>

// Standard Namespace //
using namespace std;

// Class Solution to Submit in LeetCode //
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // To make the binary search efficient, always apply it on the smaller array.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        // Length of first smaller and larger array //
        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;

        // Binary search loop
        while (low <= high) {
            // Partition nums1 at position partitionX //
            int partitionX = (low + high) / 2;
            // Partition nums2 at position partitionY so that left and right parts are balanced //
            int partitionY = (x + y + 1) / 2 - partitionX;

            // If partitionX is 0, nothing is on the left side of nums1, so we assign INT_MIN //
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            // If partitionX is at the end, there's nothing on the right side, so we assign INT_MAX //
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            // Do the same for nums2 //
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Check if we have found the correct partition //
            // That means all elements in left halves ≤ all elements in right halves //
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total number of elements is even, median is average of max of lefts and min of rights //
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } 
                // If total number of elements is odd, median is max of lefts //
                else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            // We are too far on the right side in nums1, go left //
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            // We are too far on the left side in nums1, go right //
            else {
                low = partitionX + 1;
            }
        }

        // This should never be reached if the inputs are valid sorted arrays //
        throw invalid_argument("Input arrays are not sorted properly.");
    }
};

// Main function to pass test case //
int main() {
    // Running all TestCases //
    Solution *solution = new Solution();
    vector<int> test_case_1_nums1 = {1, 3}, test_case_1_nums2 = {2};
    vector<int> test_case_2_nums1 = {1, 2}, test_case_2_nums2 = {3, 4};

    // Test Case 1 //
    if (solution->findMedianSortedArrays(test_case_1_nums1, test_case_1_nums2) == 2) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }

    // Test Case 2 //
    if (solution->findMedianSortedArrays(test_case_2_nums1, test_case_2_nums2) == 2.5) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }

    delete solution;
    return 0;
}