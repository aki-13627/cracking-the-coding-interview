#ifndef TREENODE_HPP
#define TREENODE_HPP
#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif