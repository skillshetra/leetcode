// Importing Neccessary Packages //
#include <iostream>
#include <string>

// Standard Namespace //
using namespace std;

// Definition for singly-linked list. //
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool isEqual(ListNode* other) const {
        const ListNode* a = this;
        const ListNode* b = other;
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return a == nullptr && b == nullptr;
    }
};

// Class Solution to Submit in LeetCode //
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the head of the result list //
        ListNode* dummy = new ListNode(0);
        // Tail will always point to the last node in the result list //
        ListNode* tail = dummy;
        // Variable to store carry from sum of two digits //
        int carry = 0;

        // Loop until both lists are fully traversed and no carry remains //
        while (l1 || l2 || carry) {
            // Calculate sum of current digits and carry //
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            // Update carry for next iteration //
            carry = sum / 10;

            // Create new node with digit value (sum modulo 10) and append to result //
            tail->next = new ListNode(sum % 10);
            // Move tail pointer to the new last node //
            tail = tail->next;

            // Advance input list pointers if possible //
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Return the next node after dummy which is the head of the result list //
        return dummy->next;
    }
};

// Main function to pass test case //
int main() {
    // Creating and Running Test Cases //
    Solution *solution = new Solution();
    ListNode* result_1 = solution->addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4))));
    ListNode* result_2 = solution->addTwoNumbers(new ListNode(0), new ListNode(0));
    ListNode *result_3 = solution->addTwoNumbers(new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))))))), new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))));
    delete solution;

    // Test Case 1 //
    if (result_1->isEqual(new ListNode(7, new ListNode(0, new ListNode(8))))) {
        cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
    }

    // Test Case 2 //
    if (result_2->isEqual(new ListNode(0))) {
        cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
    }

    // Test Case 3 //
    if (result_3->isEqual(new ListNode(8, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1)))))))))) {
        cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
    } else {
        cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
    }

    return 0;
}
