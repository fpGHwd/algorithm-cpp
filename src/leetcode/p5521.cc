#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int result = -1;
  int maxProductPath(vector<vector<int>> &grid) {

    vector<int> path;
    travel_right_down(grid, 0, 0, path);
    return result;
  }

  void travel_right_down(vector<vector<int>> &grid, int x, int y,
                         vector<int> &path) {

    if (x == grid.size() - 1 && y == grid[0].size() - 1) {
      int tmp = 1;
      for (int i = 0; i < path.size(); i++) {
        tmp *= path[i];
      }
      tmp *= grid[x][y];
      if (tmp > -1 && tmp > result && tmp >= 0)
        result = tmp;
      return;
    }
    path.push_back(grid[x][y]);

    if (x + 1 < grid.size())
      travel_right_down(grid, x + 1, y, path);
    if (y + 1 < grid[0].size())
      travel_right_down(grid, x, y + 1, path);

    path.pop_back();
    return;
  }
};

// 动态规划问题是递归的。递归是一种思想，解决问题的思想。非常重要，为什么我没想到
// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/discuss/855082/C%2B%2B-Dynamic-Programming-With-Comments
// 看题解很好的学习方式，学习起来，配合联系是很快的。如果纠结为什么自己没想到（细节），就是一种阻碍。开放，联系

int main(int argc, char *argv[]) {
  auto solution = new Solution();
  // string text = "  this   is  a sentence ";
  // solution->reorderSpaces(text);
  // grid = [[ 1, 4,4,0],
  // [-2, 0,0,1],
  // [ 1,-1,1,1]]

  vector<vector<int>> grid = {{1, 4, 4, 0}, {-2, 0, 0, 1}, {1, -1, 1, 1}};
  solution->maxProductPath(grid);
  return 0;
}
