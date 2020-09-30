#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        int lp[26], tmp[26];
        // memset(lp, 0, 26);
        memset(lp, 0, sizeof(lp));
        stable_sort(begin(words), end(words),
                    [](auto &a, auto &b) { return a.length() < b.length(); });
        for (char c : licensePlate) {
            if (isalpha(c))
                lp[((c >= 'A' && c <= 'Z') ? (c - 'A') : (c - 'a'))]++;
        }
        for (string s : words) {
            // memset(tmp, 0, 26);
            memset(tmp, 0, sizeof(tmp));
            for (char c : s) {
                tmp[c - 'a']++;
            }

            bool f = true;
            for (int i = 0; i < 26; i++) {
                if (lp[i] > tmp[i]) {
                    f = false;
                    break;
                }
            }
            if (f)
                return s;
        }

        return "";
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    // input for this leetcode;
    // solution->/*method for this solution*/;
    // solution->method for this solution;
    string licencePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};

    solution->shortestCompletingWord(licencePlate, words);
    return 0;
}
