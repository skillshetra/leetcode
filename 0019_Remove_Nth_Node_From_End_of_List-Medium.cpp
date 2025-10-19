// Importing Neccessary Packages //
#include <iostream>
#include <vector>

// Standard Namespace //
using namespace std;

// ListNode //
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Class Solution to Submit in LeetCode //
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before head //
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        // Move fast ahead by n+1 steps so that gap = n //
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        // Move both pointers until fast reaches end //
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // Remove the nth node //
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return dummy->next;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Helper: build linked list from vector
    auto buildList = [](const vector<int>& vals) -> ListNode* {
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int v : vals) {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
        return dummy.next;
    };
    // Helper: convert linked list to vector//
    auto toVector = [](ListNode* head) -> vector<int> {
        vector<int> out;
        while (head) {
            out.push_back(head->val);
            head = head->next;
        }
        return out;
    };
    // Helper: compare vectors//
    auto isEqual = [](vector<int> a, vector<int> b) -> bool {
        return a == b;
    };
    // Test Case 1 //
    {
        ListNode* head = buildList({1,2,3,4,5});
        int n = 2;
        ListNode* res = sol.removeNthFromEnd(head, n);
        vector<int> expected = {1,2,3,5};
        if (isEqual(toVector(res), expected)) {
            cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
        }
    }
    // Test Case 2 //
    {
        ListNode* head = buildList({1});
        int n = 1;
        ListNode* res = sol.removeNthFromEnd(head, n);
        vector<int> expected = {};
        if (isEqual(toVector(res), expected)) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    // Test Case 3 //
    {
        ListNode* head = buildList({1,2});
        int n = 1;
        ListNode* res = sol.removeNthFromEnd(head, n);
        vector<int> expected = {1};
        if (isEqual(toVector(res), expected)) {
            cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
        }
    }
    return 0;
}