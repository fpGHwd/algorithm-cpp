//
// Created by suzumiya on 4/30/19.
//

#include <vector>
#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)return 0;
        TreeNode *temp = root;
        TreeNode *save = root->right;
        while(temp->left){
            if(temp->right)save = temp->right;
            temp = temp->left;
        }

        if(k==1)return temp->val;
        else return kthSmallest(save,k-1);
    }
};

int main(int argc, char **argv){
    vector<int> nums = {5,3,6,2,4,1};
    TreeNode *root;
    root = makeBinarySearchTree(root, nums);

    return 0;
}