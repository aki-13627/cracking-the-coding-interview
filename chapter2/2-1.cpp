#include <iostream>
#include <unordered_set>
#include "./listNode.hpp"
using namespace std;

class Solution
{
public:
    ListNode *removeDuplicate(ListNode *node)
    {
        unordered_set<int> vals;
        ListNode *head = node;
        ListNode *prev = nullptr;

        while (node)
        {
            if (!vals.count(node->val))
            {
                vals.insert(node->val);
                prev = node;
                node = node->next;
            }
            else
            {
                prev->next = node->next;
                node = node->next;
            }
        }

        return head; // ここで最初のheadを返す
    }
};

ListNode *createListFromInput(int n)
{
    int val;
    cin >> val;
    ListNode *head = new ListNode(val);
    ListNode *current = head;

    for (int i = 1; i < n; i++)
    {
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    ListNode *p = createListFromInput(n);
    Solution sol;

    ListNode *result = sol.removeDuplicate(p);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
}