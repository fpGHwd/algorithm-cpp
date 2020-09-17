#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(result, path, candidates, 0, target);
    return result;
  }

  void dfs(vector<vector<int>> &ret, vector<int> path, vector<int> &candidates,
           int start, int target) {
    if (target == 0) {
      ret.push_back(path);
      return;
    } else if (target < 0) {
      return;
    } else {
      for (int i = start; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        dfs(ret, path, candidates, i, target - candidates[i]);
        path.pop_back();
      }
    }
  }
};

int main(int arch, char **argv) {
  auto s = new Solution();
  vector<int> input = {2, 3, 6, 7};
  int t = 10;
  s->combinationSum(input, t);
  return 0;
}
