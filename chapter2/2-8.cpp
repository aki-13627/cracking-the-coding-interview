#include <bits/stdc++.h>

#include "./listNode.hpp"
using namespace std;

class Solution {
   public:
    ListNode *findBeginning(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (!fast || fast->next == nullptr) {
            return nullptr;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
void runTest(const vector<int> &values, int pos, const string &testName) {
    Solution sol;
    ListNode *head = createCyclicList(values, pos);
    ListNode *cycleStart = sol.findBeginning(head);

    cout << "[" << testName << "] ";
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
}
int main() {
    runTest({3, 2, 0, -4}, 1, "Case 1: Cycle at pos 1");
    runTest({1, 2}, -1, "Case 2: No cycle");
    runTest({1, 2, 3}, 0, "Case 3: Cycle at head");
    runTest({1}, 0, "Case 4: Single node cycle");
    runTest({}, -1, "Case 5: Empty list");

    return 0;
}