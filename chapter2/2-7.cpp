#include <bits/stdc++.h>

#include "./listNode.hpp"
using namespace std;

class Solution {
   public:
    ListNode* isSameList(ListNode* node1, ListNode* node2) {
        ListNode* n1 = node1;
        ListNode* n2 = node2;
        int len1 = 0;
        int len2 = 0;
        while (n1 || n2) {
            if (n1) {
                n1 = n1->next;
                len1++;
            }
            if (n2) {
                n2 = n2->next;
                len2++;
            }
        }
        while (len1 > len2) {
            node1 = node1->next;
            len1--;
        }
        while (len2 > len1) {
            node2 = node2->next;
            len2--;
        }
        while (node1 && node2) {
            if (node1 == node2) {
                return node1;
            } else {
                node1 = node1->next;
                node2 = node2->next;
            }
        }
        return nullptr;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // 最初の部分を入力から構築
    ListNode* aHead = createListFromInput(n);
    ListNode* bHead = createListFromInput(m);

    ListNode* common = new ListNode(8);
    common->next = new ListNode(9);

    ListNode* aTail = aHead;
    while (aTail->next) aTail = aTail->next;
    aTail->next = common;

    // Bの末尾に共通部分を接続
    ListNode* bTail = bHead;
    while (bTail->next) bTail = bTail->next;
    bTail->next = common;

    Solution sol;
    ListNode* res = sol.isSameList(aHead, bHead);

    if (res) {
        while (res) {
            cout << res->val << " ";
            res = res->next;
        }
    } else {
        cout << "共通ノードなし";
    }

    return 0;
}