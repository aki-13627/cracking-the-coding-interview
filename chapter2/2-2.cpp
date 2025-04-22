#include <bits/stdc++.h>

#include "./listNode.hpp"
using namespace std;

// 長さはわかっていない前提であることが多い
// ２ポインタ法を使って1回分の走査で実装できる
class Solution {
   public:
    ListNode* returnBackK(ListNode* node, int k) {
        ListNode* head = node;
        int len = 0;
        while (node) {
            node = node->next;
            len++;
        }
        if (k > len) return nullptr;
        for (int i = 0; i < len - k; i++) {
            head = head->next;
        }
        return head;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    ListNode* p = createListFromInput(n);
    Solution sol;
    ListNode* res = sol.returnBackK(p, k);

    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}