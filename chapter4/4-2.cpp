/* given a ascending sorted array of integers, create a binary
search tree with minimal height
*/

#include <bits/stdc++.h>
#include "./treeNode.hpp"
using namespace std;

class Solution {
   public:
    TreeNode* sortedArrayToBinaryTree(vector<int> array) {
        return buildBST(array, 0, array.size() - 1);
    }

   private:
    TreeNode* buildBST(const vector<int>& array, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(array[mid]);
        node->left = buildBST(array, left, mid - 1);
        node->right = buildBST(array, mid + 1, right);
        return node;
    }
};

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}


int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    Solution sol;
    TreeNode* root = sol.sortedArrayToBinaryTree(array);
    printInOrder(root);
    cout << endl;
}