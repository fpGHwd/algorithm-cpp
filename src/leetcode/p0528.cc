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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode *root) {
        depthTravel(root);
        return diameter;
    }
    int depthTravel(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = depthTravel(root->left);
        int right = depthTravel(root->right);
        diameter = max(left + right, diameter);
        return 1 + max(left, right);
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    solution->depthTravel(root);

    return 0;
}
