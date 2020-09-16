//
// Created by suzumiya on 4/10/19.
//

#ifndef BEAUTY_IN_CODE_TREE_H
#define BEAUTY_IN_CODE_TREE_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * struct Node{
    bool have_value; // 是否有值
    int v; // 节点值
    Node *left, *right; // 左右节点
    Node():have_value(false), left(nullptr), right(nullptr){} // 构造函数
};
 */

TreeNode* makeBinarySearchTree(TreeNode *&root, vector<int> nums);

#endif //BEAUTY_IN_CODE_TREE_H
