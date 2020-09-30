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
    vector<int> shortestToChar(string S, char C) {
        vector<int> e_vi;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C)
                e_vi.push_back(i);
        }

        vector<int> sc_vi;
        int e_left = -1, e_right = -1;
        for (int i = 0; i < S.length(); i++) {
            if (e_right < i) {
                e_right = i + 1;
                while (e_right < (int)S.length() && S[e_right] != C)
                    e_right++;
            }
            if (S[i] == C)
                e_left = i;
            if (e_left == -1)
                sc_vi.push_back(abs(e_right - i));
            else if (e_right == (int)S.length())
                sc_vi.push_back(abs(e_left - i));
            else
                sc_vi.push_back(min(abs(e_left - i), abs(e_right - i)));
        }

        return sc_vi;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    string S = "loveleetcode";
    char C = 'e';

    solution->shortestToChar(S, C);

    return 0;
}
