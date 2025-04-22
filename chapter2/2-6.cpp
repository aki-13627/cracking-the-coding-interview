#include <bits/stdc++.h>

#include "./listNode.hpp"
using namespace std;

class Solution {
   public:
    bool isPalindromList(ListNode* node) {
        if (!node || !node->next) return true;
        ListNode* fast = node;
        ListNode* slow = node;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        while (prev) {
            if (node->val != prev->val) {
                return false;
            }
            node = node->next;
            prev = prev->next;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    ListNode* p = createListFromInput(n);
    Solution sol;
    bool res = sol.isPalindromList(p);
    cout << (res ? "true" : "false") << endl;
    return 0;
}