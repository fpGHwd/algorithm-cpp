#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
        bool isSubtree(TreeNode* s, TreeNode* t) {
            if(s == nullptr && t == nullptr){
                return true;
            }
            if(s == nullptr || t == nullptr)return false;
            if(s->val != t->val) return false;
            else // s->val == t->val
                return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
};

int main(int arch, char **argv){
    auto s = new Solution();

/**
 * [3,4,5,1,2,null,null,0]
 * [4,1,2]
 */

    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(4); root->right = new TreeNode(5);
    root->left->left = new TreeNode(1); root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(0);

    TreeNode * t = new TreeNode(4);
    t->left = new TreeNode(1); t->right = new TreeNode(2);

    bool result = s->isSubtree(root, t);

    cout << result << endl;

    return 0;
}
