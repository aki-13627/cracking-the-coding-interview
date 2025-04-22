#include <bits/stdc++.h>

#include "./listNode.hpp"
using namespace std;

class Solution {
   public:
    int sumOfLinkedLists(ListNode *node1, ListNode *node2) {
        int k = 1;
        int sum = 0;
        int carry = 0;

        while (node1 || node2 || carry) {
            int val1 = node1 ? node1->val : 0;
            int val2 = node2 ? node2->val : 0;
            int total = val1 + val2 + carry;

            sum += k * (total % 10);
            carry = total / 10;

            if (node1) node1 = node1->next;
            if (node2) node2 = node2->next;

            k *= 10;
        }

        return sum;
    }
    int sumOfLinkedListsReverse(ListNode *node1, ListNode *node2) {
        ListNode *prev1 = nullptr;
        while (node1) {
            ListNode *next = node1->next;
            node1->next = prev1;
            prev1 = node1;
            node1 = next;
        }
        ListNode *prev2 = nullptr;
        while (node2) {
            ListNode *next = node2->next;
            node2->next = prev2;
            prev2 = node2;
            node2 = next;
        }
        return sumOfLinkedLists(prev1, prev2);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    ListNode *p = createListFromInput(n);
    ListNode *q = createListFromInput(m);
    Solution sol;
    int res = sol.sumOfLinkedLists(p, q);
    int resRev = sol.sumOfLinkedListsReverse(p, q);
    cout << res << ", " << resRev << endl;
    return 0;
}