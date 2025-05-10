/*
二分探索木において、与えられたノードの「次の」ノード（in-orderの走査で）を探すアルゴリズムを設計してください
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNodeWithParent {
    int val;
    TreeNodeWithParent* left;
    TreeNodeWithParent* right;
    TreeNodeWithParent* parent;
    TreeNodeWithParent(int x)
        : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
   public:
    TreeNodeWithParent* inOrderSucc(TreeNodeWithParent* node) {
        if (!node) return nullptr;
        if (node->right != nullptr) {
            return deepestLeft(node->right);
        } else {
            TreeNodeWithParent* current = node;
            TreeNodeWithParent* parent = node->parent;
            while (parent != nullptr && parent->left != current) {
                current = parent;
                parent = parent->parent;
            }
            return parent;
        }
    }

    TreeNodeWithParent* deepestLeft(TreeNodeWithParent* root) {
        if (root->left) return deepestLeft(root->left);
        return root;
    }
};

int main() {
    // 木の構築
    /*
           5
          / \
         3   8
        / \   \
       2   4   9
    */

    TreeNodeWithParent* n5 = new TreeNodeWithParent(5);
    TreeNodeWithParent* n3 = new TreeNodeWithParent(3);
    TreeNodeWithParent* n8 = new TreeNodeWithParent(8);
    TreeNodeWithParent* n2 = new TreeNodeWithParent(2);
    TreeNodeWithParent* n4 = new TreeNodeWithParent(4);
    TreeNodeWithParent* n9 = new TreeNodeWithParent(9);

    n5->left = n3; n3->parent = n5;
    n5->right = n8; n8->parent = n5;
    n3->left = n2; n2->parent = n3;
    n3->right = n4; n4->parent = n3;
    n8->right = n9; n9->parent = n8;

    Solution sol;

    TreeNodeWithParent* nodes[] = {n2, n3, n4, n5, n8, n9};

    for (auto node : nodes) {
        TreeNodeWithParent* succ = sol.inOrderSucc(node);
        if (succ) {
            cout << "Node " << node->val << " -> Next: " << succ->val << endl;
        } else {
            cout << "Node " << node->val << " -> Next: nullptr" << endl;
        }
    }

    return 0;
}