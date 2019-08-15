//
// Created by suzumiya on 4/30/19.
//

#include <vector>
#include <iostream>
#include "tree.h"
#include <stack>

using namespace std;

// 忘了数学，忘了其他所有的东西，都是一样的。复用/做好手头上的事情就是最大的效率

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
//    int kthSmallest(TreeNode* root, int k) {
//        if(root == nullptr)return 0;
//        TreeNode *temp = root;
//        TreeNode *save = root->right, *saveRoot = root;
//        while(temp->left){
//            if(temp->right) {
//                save = temp->right;
//                saveRoot = temp;
//            }
//            temp = temp->left;
//        }
//
//        if(k==1)return temp->val;
//        else{
//            if(root->left != save)return kthSmallest(save,k-1);
//        }
//    }
// 无法计数的，非递归的中序遍历

// 对参数进行控制也是题目本身（的限制）啊

    int kthSmallest(TreeNode *root, int k) {
        if(!root)return 0; // todo: 不知道是什么意思
        int ls = calcTreeSize(root->left);
        if(ls+1==k){
            return root->val;
        }else if(ls >= k){
            return kthSmallest(root->left,k);
        }else{
            return kthSmallest(root->right, k-ls-1);
        }
    }

    int calcTreeSize(TreeNode *root){
        if(!root)return 0;
        else return 1+calcTreeSize(root->left)+calcTreeSize(root->right);
    }

    // https://blog.csdn.net/suibianshen2012/article/details/52051272
};

int main(int argc, char **argv) {
    vector<int> nums = {5, 3, 6, 2, 4, 1};
    TreeNode *root = nullptr;
    makeBinarySearchTree(root, nums);

    auto sl = new Solution();
    cout << sl->kthSmallest(root, 3);

    return 0;
}

//执行用时 : 40 ms, 在Kth Smallest Element in a BST的C++提交中击败了94.24% 的用户
//内存消耗 : 22 MB, 在Kth Smallest Element in a BST的C++提交中击败了5.00% 的用户