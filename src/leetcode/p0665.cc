#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {
    }
};

class Solution {
  public:
    int luvp = 0;
    int longestUnivaluePath(TreeNode *root) {
        travelPath(root);
        return luvp - 1;
    }

    int travelPath(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left = 0, right = 0;
        if (root->left != nullptr)
            left = travelPath(root->left);
        if (root->right != nullptr)
            right = travelPath(root->right);
        int root_value_length =
            1 + (root->left && root->left->val == root->val ? left : 0) +
            (root->right && root->right->val == root->val ? right : 0);
        luvp = max(luvp, root_value_length);
        return root_value_length;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int lup = solution->longestUnivaluePath(root);

    return 0;
}
