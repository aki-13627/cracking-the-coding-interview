#include <bits/stdc++.h>

using namespace std;

class TreeNode {
   public:
    int val;
    int size;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), size(1), left(nullptr), right(nullptr) {}
};

class Solution {
   private:
    mt19937 gen;

    int getSize(TreeNode* node) {
        return node ? node->size : 0;
    }

   public:
   Solution() {
    random_device rd;
    gen.seed(rd());
   }

   TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    // size 更新
    root->size = 1 + getSize(root->left) + getSize(root->right);
    return root;
}

    TreeNode* getRandomNode(TreeNode* node) {
        int leftSize = node->left ? node->left->size : 0;
        int totalSize = node->size;
        uniform_int_distribution<> dist(1, totalSize);
        int k = dist(gen);
        if (k <= leftSize) {
            return getRandomNode(node->left);
        } else if (k == leftSize + 1) {
            return node;
        } else {
            return getRandomNode(node->right);
        }
    }
};

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // BSTに値を挿入
    vector<int> vals = {10, 5, 15, 3, 7, 13, 17};
    for (int v : vals) {
        root = sol.insert(root, v);
    }

    cout << "ランダムに選ばれたノードの値（10回）:\n";
    for (int i = 0; i < 10; ++i) {
        TreeNode* rnd = sol.getRandomNode(root);
        cout << rnd->val << " ";
    }
    cout << endl;

    return 0;
}


// class Solution {
//    public:
//     int getRondomNode(TreeNode* root) {
//         vector<int> values = getAllVal(root);

//         random_device rd;
//         mt19937 gen(rd());
//         uniform_int_distribution<> dist(
//             0, values.size() - 1);

//         return values[dist(gen)];
//     }
//     vector<int> getAllVal(TreeNode* root) {
//         vector<int> values;
//         if (!root) return {};
//         values.push_back(root->val);
//         vector<int> leftValues = getAllVal(root->left);
//         vector<int> rightValues = getAllVal(root->right);

//         values.insert(values.end(), leftValues.begin(), leftValues.end());
//         values.insert(values.end(), rightValues.begin(), rightValues.end());

//         return values;
//     }
// };

// int main() {
//     /*
//            10
//           /  \
//          5    15
//         / \     \
//        3   7     20
//     */

//     TreeNode* root = new TreeNode(10);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(15);
//     root->left->left = new TreeNode(3);
//     root->left->right = new TreeNode(7);
//     root->right->right = new TreeNode(20);

//     Solution sol;

//     cout << "ランダムノード選択テスト（10回）:\n";
//     for (int i = 0; i < 10; ++i) {
//         int val = sol.getRondomNode(root);
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }
