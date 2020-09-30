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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {

        vector<vector<int>> result;

        // vector<int> ret;
        queue<TreeNode *> q;
        TreeNode *last, *end;
        if (root) {
            q.push(root);
            end = root;
            last = end;
            result.push_back(vector<int>{});
        }
        while (!q.empty()) {
            TreeNode *temp = q.front();
            // if (temp == last) {
            //     result.push_back(vector<int>{});
            // }
            result[result.size() - 1].push_back(temp->val);
            q.pop();
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp == last && !q.empty())
                result.push_back(vector<int>{});
            if (temp == last) {
                last = q.back();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();

    return 0;
}
