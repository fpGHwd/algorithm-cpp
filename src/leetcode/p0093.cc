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
    vector<string> addresses;
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        dfs(s, path);
        return addresses;
    }

    void dfs(string s, vector<string> &path) {

        if (s == "" && path.size() == 4) {
            string tmp = "";
            for (string s : path) {
                if (tmp != "")
                    tmp += ".";
                tmp += s;
            }
            addresses.push_back(tmp);
            return;
        }

        if (path.size() > 4 || s == "")
            return;

        for (int i = 1; i <= s.length(); i++) {
            string ip = s.substr(0, i);
            if (i > 1 && s[0] == '0') // 10.0.010.0 避免 010 這樣的標識
                return;
            if (stoi(ip) > 255)
                break;
            path.push_back(ip);
            dfs(s.substr(i, s.length() - i), path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    string s = "25525511135";
    // solution->/*method for this solution*/;
    // solution->method for this solution;
    solution->restoreIpAddresses(s);

    return 0;
}
