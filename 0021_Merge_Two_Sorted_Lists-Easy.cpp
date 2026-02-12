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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // Attach the remaining nodes //
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

// Main function to pass test case //
int main() {
    Solution sol;
    // Helper: build linked list from vector //
    auto buildList = [](const vector<int>& vals) -> ListNode* {
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int v : vals) {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
        return dummy.next;
    };
    // Helper: convert linked list to vector //
    auto toVector = [](ListNode* head) -> vector<int> {
        vector<int> out;
        while (head) {
            out.push_back(head->val);
            head = head->next;
        }
        return out;
    };
    // Helper: compare vectors //
    auto isEqual = [](vector<int> a, vector<int> b) -> bool {
        return a == b;
    };
    // Test Case 1 //
    {
        ListNode* l1 = buildList({1,2,4});
        ListNode* l2 = buildList({1,3,4});
        ListNode* res = sol.mergeTwoLists(l1, l2);
        vector<int> expected = {1,1,2,3,4,4};
        if (isEqual(toVector(res), expected)) {
            cout << "\033[32mTest Case 1 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 1 Failed.\033[0m" << endl;
        }
    }
    // Test Case 2 //
    {
        ListNode* l1 = buildList({});
        ListNode* l2 = buildList({});
        ListNode* res = sol.mergeTwoLists(l1, l2);
        vector<int> expected = {};
        if (isEqual(toVector(res), expected)) {
            cout << "\033[32mTest Case 2 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 2 Failed.\033[0m" << endl;
        }
    }
    // Test Case 3 //
    {
        ListNode* l1 = buildList({});
        ListNode* l2 = buildList({0});
        ListNode* res = sol.mergeTwoLists(l1, l2);
        vector<int> expected = {0};
        if (isEqual(toVector(res), expected)) {
            cout << "\033[32mTest Case 3 Passed.\033[0m" << endl;
        } else {
            cout << "\033[31mTest Case 3 Failed.\033[0m" << endl;
        }
    }
    return 0;
}