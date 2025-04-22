#include <bits/stdc++.h>

#include "./listNode.hpp"
using namespace std;

class Solution {
   public:
    /*
    単方向連結リストにおいて、間の要素で、その要素のみアクセス可能であるとします。
    その要素を削除するアルゴリズムを実装してください。
    */
    void remuveNode(ListNode *toRemove) {
        if (toRemove->next == nullptr) {
            return;
        }
        ListNode *next = toRemove->next;
        toRemove->val = next->val;
        toRemove->next = next->next;
        delete next;
    }
};

int main() { return 0; }