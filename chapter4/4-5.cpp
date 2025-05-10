#include <bits/stdc++.h>
#include "./treeNode.hpp"
using namespace std;

class Solution {
    public:
        bool isBST(TreeNode* root) {
            return validate(root, LONG_MIN, LONG_MAX);
        }

        bool validate(TreeNode* node, long minVal, long maxVal) {
            if(!node) return true;
            if(node->val <= minVal || node->val >= maxVal) {
                return false;
            }

            return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
        }
};

// BSTを作成（正しい構造）
TreeNode* buildValidBST() {
    //     5
    //    / \
    //   3   7
    //  / \   \
    // 2   4   9
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);
    return root;
}

// BSTではない木を作成
TreeNode* buildInvalidBST() {
    //     5
    //    / \
    //   3   4   ← ここが不正（4 は 5 より小さいので右に来てはいけない）
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4); // BST違反
    return root;
}

int main() {
    Solution sol;

    TreeNode* bst = buildValidBST();
    TreeNode* notBst = buildInvalidBST();

    cout << "Valid BST: " << (sol.isBST(bst) ? "true" : "false") << endl;
    cout << "Invalid BST: " << (sol.isBST(notBst) ? "true" : "false") << endl;

    return 0;
}