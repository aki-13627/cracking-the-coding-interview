#include <bits/stdc++.h>
#include "./treeNode.hpp"
using namespace std;

class Solution {
    public:
        bool isBalancedWorse(TreeNode* root) {
            if(!root) return true;
            int heightDiff = abs(getDepth(root->left) - getDepth(root->right));
            if(heightDiff > 1) {
                return false;
            } else {
                return isBalancedWorse(root->left) && isBalancedWorse(root->right);
            }
        }

        int getDepth(TreeNode* root) {
            if(!root) return -1;
            return max(getDepth(root->left), getDepth(root->right)) + 1;
        }

        bool isBalanced(TreeNode* root) {
            return !root || checkHeight(root) != INT_MIN;
        }

        int checkHeight(TreeNode* root) {
            if(!root) return -1;
            int leftHeight = checkHeight(root->left);
            if(leftHeight == INT_MIN) return INT_MIN;
            int rightHeight = checkHeight(root->right);
            if(rightHeight == INT_MIN) return INT_MIN;
            
            int heightDiff = abs(leftHeight - rightHeight);
            if(heightDiff > 1) return INT_MIN;
            return max(leftHeight, rightHeight) +1;
        }
};

// バランスの取れた木を作成
TreeNode* buildBalancedTree() {
    //     4
    //    / \
    //   2   6
    //  / \   \
    // 1   3   7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    return root;
}

// アンバランスな木を作成
TreeNode* buildUnbalancedTree() {
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;

    TreeNode* balanced = buildBalancedTree();
    TreeNode* unbalanced = buildUnbalancedTree();

    cout << "Balanced tree: " << (sol.isBalanced(balanced) ? "true" : "false") << endl;
    cout << "Unbalanced tree: " << (sol.isBalanced(unbalanced) ? "true" : "false") << endl;

    return 0;
}