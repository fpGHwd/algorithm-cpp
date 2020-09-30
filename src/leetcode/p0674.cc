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
    int countBinarySubstrings(string s) {
        if (s == "")
            return 0;
        vector<int> vi_pos;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1])
                vi_pos.push_back(i);
        }
        int count = 0, left, right;
        for (int i = 0; i < vi_pos.size(); i++) {
            left = vi_pos[i] - (i == 0 ? 0 : vi_pos[i - 1]);
            right = ((i == vi_pos.size() - 1) ? s.length() : vi_pos[i + 1]) -
                    vi_pos[i];
            count += min(left, right);
        }
        return count;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    string s = "00110";

    solution->countBinarySubstrings(s);

    return 0;
}
