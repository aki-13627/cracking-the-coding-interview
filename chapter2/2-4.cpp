#include <bits/stdc++.h>
#include "./listNode.hpp"
using namespace std;

class Solution
{
public:
    ListNode *partition(ListNode *node, int x)
    {
        ListNode *dummyBefore = new ListNode(-1);
        ListNode *dummyAfter = new ListNode(-1);
        ListNode *before = dummyBefore;
        ListNode *after = dummyAfter;
        while (node)
        {
            if (node->val >= x)
            {
                after->next = node;
                after = after->next;
            }
            else
            {
                before->next = node;
                before = before->next;
            }
            node = node->next;
        }

        after->next = nullptr;
        before->next = dummyAfter->next;
        ListNode* result =  dummyBefore->next;
        delete dummyBefore; delete dummyAfter;
        return result;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    ListNode *p = createListFromInput(n);
    Solution sol;
    ListNode *res = sol.partition(p, k);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}