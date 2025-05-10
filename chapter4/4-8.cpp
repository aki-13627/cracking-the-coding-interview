#include <bits/stdc++.h>
#include "./treeNode.hpp"
using namespace std;

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
            if(!root || root == node1 || root == node2) return root;
            TreeNode* left = lowestCommonAncestor(root->left, node1, node2);
            TreeNode* right = lowestCommonAncestor(root->right, node1, node2);
            if(left && right) return root;
            return left ? left : right;
        }
};

int main() {
    // テスト用ツリー構築
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);

    root->left = n5; root->right = n1;
    n5->left = n6; n5->right = n2;
    n1->left = n0; n1->right = n8;
    n2->left = n7; n2->right = n4;

    Solution sol;

    // テストケース
    assert(sol.lowestCommonAncestor(root, n5, n1) == root);
    assert(sol.lowestCommonAncestor(root, n5, n4) == n5);
    assert(sol.lowestCommonAncestor(root, n6, n4) == n5);
    assert(sol.lowestCommonAncestor(root, n7, n8) == root);
    assert(sol.lowestCommonAncestor(root, n0, n8) == n1);

    cout << "All tests passed!" << endl;

    // メモリ解放（ここでは省略）
    return 0;
}