#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        vector<vector<int>> vvi;

        for (vector<int> vi : A) {
            for (int i = 0; i < vi.size() / 2; i++) {
                int tmp = vi[i];
                vi[i] = vi[vi.size() - 1 - i];
                vi[vi.size() - 1 - i] = tmp;
            }

            for (int i = 0; i < vi.size(); i++) {
                vi[i] = ((vi[i] == 1) ? 0 : 1);
            }

            vvi.push_back(vi);
        }

        return vvi;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    vector<vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    solution->flipAndInvertImage(A);

    return 0;
}
