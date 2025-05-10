#include <bits/stdc++.h>
#include "./treeNode.hpp"
using namespace std;

// t1はt2に比べてかなり大きいに分木
class Solution {
    public:
        bool isSubtree(TreeNode* t1, TreeNode* t2) {
            if(!t1) return false;
            if(isSameTree(t1, t2)) return true;
            return isSubtree(t1->left, t2) || isSubtree(t1->left, t2);
        }

        bool isSameTree(TreeNode* a, TreeNode* b) {
            if(!a && !b) return true;
            if(!a || !b) return false;
            if(a->val != b->val) return false;
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
};

int main() {
    /*
        T1:
            3
           / \
          4   5
         / \
        1   2

        T2:
          4
         / \
        1   2
    */

    TreeNode* t1 = new TreeNode(3);
    t1->left = new TreeNode(4);
    t1->right = new TreeNode(5);
    t1->left->left = new TreeNode(1);
    t1->left->right = new TreeNode(2);

    TreeNode* t2 = new TreeNode(4);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(2);

    Solution sol;

    cout << boolalpha;

    cout << "T2 is subtree of T1: " << sol.isSubtree(t1, t2) << endl;

    // 失敗ケース
    TreeNode* t3 = new TreeNode(4);
    t3->left = new TreeNode(1);
    t3->right = new TreeNode(3); // 値が違う

    cout << "T3 is subtree of T1: " << sol.isSubtree(t1, t3) << endl;

    return 0;
}
