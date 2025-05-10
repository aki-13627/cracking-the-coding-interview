#include <bits/stdc++.h>
#include "./treeNode.hpp"
using namespace std;

class Solution {
    public:
        vector<vector<int>> allSequences(TreeNode* root) {
            vector<vector<int>> result;
            if(!root) {
                result.push_back({});
                return result;
            }

            vector<int> prefix = {root->val};

            vector<vector<int>> leftSeqs = allSequences(root->left);
            vector<vector<int>> rightSeqs = allSequences(root->right);

            for(auto& left : leftSeqs) {
                for(auto& right : rightSeqs) {
                    vector<vector<int>> weaved;
                    weaveLists(left, right, prefix, weaved);
                    result.insert(result.end(), weaved.begin(), weaved.end());
                }
            }

            return result;
        }

        void weaveLists(vector<int>& first, vector<int>&second, vector<int> prefix, vector<vector<int>> &results) {
            if(first.empty() || second.empty()) {
                vector<int> result = prefix;
                result.insert(result.end(), first.begin(), first.end());
                result.insert(result.end(), second.begin(), second.end());
                results.push_back(result);
                return;
            }
            int headFirst = first[0];
            first.erase(first.begin());
            prefix.push_back(headFirst);
            weaveLists(first, second, prefix, results);
            prefix.pop_back();
            first.insert(first.begin(), headFirst);


            int headSecond = second[0];
            second.erase(second.begin());
            prefix.push_back(headSecond);
            weaveLists(first, second, prefix, results);
            prefix.pop_back();
            second.insert(second.begin(), headSecond);
        }
};

int main() {
    /*
            4
           / \
          2   5
         / \
        1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    auto sequences = sol.allSequences(root);

    for (const auto& seq : sequences) {
        for (int n : seq) cout << n << " ";
        cout << endl;
    }

    return 0;
}
