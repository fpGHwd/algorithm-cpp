//
// Created by suzumiya on 4/10/19.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <cstdio>
#include "tree.h"
#include <vector>
#include <stack>

using namespace std;


// 首先想到的方法是分别遍历到p点和q点，然后对比路径获得最近的父结点。思路没有问题，奇迹淫巧就是另外的问题了。
// 然后是后续来搜索。

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL)return NULL;
        while((root->val - p->val) * (root->val - q->val) >0){ // 同侧，还可以继续
            if(p->val < root->val){
                root=root->left;
            }else{
                root=root->right;
            }
        }
        return root;
    }
};

int main(int argc, char **argv){

    return 0;
}

