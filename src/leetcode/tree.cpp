//
// Created by suzumiya on 4/30/19.
//

#include <vector>
#include "tree.h"

using namespace std;

// 如果说研究数学和桥代码并没有什么区别，那么我为什么要在敲代码的时候纠结于数学呢。
// 应该是有毒把。
// 因为我手上就有一个电脑，而不是研究数学的心态和其他的东西。所以我最好还是敲代码/复用/时间效率最大化。
// 我从来都没有认真想过，自己要不要做好手边的事情，而不是为了杂七杂八的事情浪费自己现在的时间。

// recursion version
bool insertTreeNode(TreeNode *& root , int val){
    auto *node = new TreeNode(val);
    if(!root){
        root = node;
        return true;
    }else
        if(val < root->val)
            return insertTreeNode(root->left, val);
        else
            return insertTreeNode(root->right, val);
}

TreeNode* makeBinarySearchTree(TreeNode *& root,vector<int> nums){
    for(auto n:nums){
        insertTreeNode(root, n);
    }
    return root;
}