#include <bits/stdc++.h>
#include "./treeNode.hpp"
#include "../chapter2/listNode.hpp"
using namespace std;

class Solution {
    public:
        vector<ListNode*> BSTToListNodes(TreeNode* root) {
            vector<ListNode*> result;
            if(!root) return result;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                int levelSize = q.size();
                ListNode* dummy = new ListNode(0);
                ListNode* current  = dummy;
                for(int i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    current->next = new ListNode(node->val);
                    current = current->next;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                result.push_back(dummy->next);
            }

            return result;
        }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " → ";
        head = head->next;
    }
    cout << endl;
}

// BSTを手動で作成する
TreeNode* buildSampleBST() {
    //       4
    //     /   \
    //    2     6
    //   / \   / \
    //  1   3 5   7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = buildSampleBST();
    Solution sol;
    vector<ListNode*> lists = sol.BSTToListNodes(root);

    for (int i = 0; i < lists.size(); ++i) {
        cout << "Level " << i << ": ";
        printList(lists[i]);
    }

    return 0;
}