#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    int n = 0;
    for (char c : S) {
      if (isalnum(c))
        n++;
    }

    int f = n % K;
    string s;
    int i = 0;

    while (f-- > 0) {
      while (i < S.length() && !isalnum(S[i]))
        i++;
      if (i < S.length())
        s.append(1, toupper(S[i++]));
    }

    for (int k = i; k < S.length();) {
      while (k < S.length() && !isalnum(S[k]))
        k++;
      if (k < S.length() && s.length() != 0)
        s.append(1, '-');
      f = K;
      while (k < S.length() && f--) {
        while (k < S.length() && !isalnum(S[k]))
          k++;
        if (i < S.length())
          s.append(1, toupper(S[k++]));
      }
    }

    return s;
  }
};

int main(int arch, char **argv) {
  string S = "5F3Z-2e-9-w";
  int K = 4;
  auto s = new Solution();
  s->licenseKeyFormatting(S, K);
  return 0;
}
