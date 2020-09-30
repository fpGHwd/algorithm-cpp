#include <algorithm>
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
    bool backspaceCompare(string S, string T) {
        stack<char> sc, sc1;
        for (char c : S) {
            if (!sc.empty() && c == '#')
                sc.pop();
            if (c != '#')
                sc.push(c);
        }

        for (char c : T) {
            if (!sc1.empty() && c == '#')
                sc1.pop();
            if (c != '#')
                sc1.push(c);
        }

        if (sc.size() != sc1.size())
            return false;
        while (!sc.empty() && !sc1.empty()) {
            if (sc.top() != sc1.top())
                return false;
            sc.pop();
            sc1.pop();
        }
        return true;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    string a = "a#c", b = "b";
    // solution->/*method for this solution*/;
    solution->backspaceCompare(a, b);

    return 0;
}
