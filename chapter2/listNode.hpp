#include <bits/stdc++.h>
#ifndef LISTNODE_HPP
#define LISTNODE_HPP
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif // LISTNODE_HPP 

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

ListNode* createCyclicList(const vector<int>& values, int pos) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* loopEntry = nullptr;

    for (int i = 0; i < values.size(); ++i) {
        ListNode* node = new ListNode(values[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        if (i == pos) {
            loopEntry = node;
        }
    }

    if (tail && loopEntry) {
        tail->next = loopEntry; // サイクルを作る
    }

    return head;
}