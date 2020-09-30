#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool rotateString(string A, string B) {
    if (A.length() != B.length())
      return false;
    int len = A.length(), i = len;
    char c;
    while (i - 1 > 0) {
      c = A[0];
      A = A.substr(1, len - 1);
      A = A.append(1, c);
      if (A == B)
        return true;
      i--;
    }

    return false;
  }
};

int main(int arch, char **argv) {
  string A = "abcde", B = "cdeab";
  auto solution = new Solution();
  cout << solution->rotateString(A, B) << endl;

  return 0;
}
