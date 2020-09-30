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
    bool isMatch(string s, string p) {
        if (s.length() == 0 && p.length() == 0)
            return true;
        if (s.length() == 0 || p.length() == 0)
            return false;
        int m = 0, n = 0;
        while (m < s.length() && n < p.length() && s[m] == p[n])
            m++, n++;
        if (m == s.length() && n == p.length())
            return true;

        if (p[n] == p.length())
            return false;

        if (p[n] == '.') {
            m++, n++;
            return isMatch(s.substr(m, s.length() - m),
                           p.substr(n, p.length() - n));
        } else if (p[n] == '*') {
            if (n - 1 < 0)
                return false;
            bool b = false;
            for (int i = 0; i <= s.length() - m; i++) {
                if (isMatch(s.substr(m, s.length() - m),
                            p.substr(n, p.length() - n).insert(0, i, p[n - 1])))
                    b = true;
                if (b)
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    string s = "aac", p = "a.*";
    solution->isMatch(s, p);

    return 0;
}
