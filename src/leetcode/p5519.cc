#include <string>

using namespace std;

class Solution {
public:
  string reorderSpaces(string text) {
    int i = 0, num_spc = 0, num_str = 0;
    while (i < text.length() && text[i] == ' ')
      num_spc++, i++;
    while (i < text.length()) {
      num_str++;
      while (i < text.length() && text[i] != ' ')
        i++;
      while (i < text.length() && text[i] == ' ')
        num_spc++, i++;
    }
    string result = "";
    int k = 0, tmp = 0, start = 0, count = 0;
    while (k < text.length() && text[k] == ' ')
      k++;
    if (num_str == 1) {
      start = k;
      while (k < text.length() && text[k] != ' ')
        tmp++, k++;
      result.append(text.substr(start, tmp));
      result.append(num_spc, ' ');
      return result;
    }
    int average_spc = num_spc / (num_str - 1),
        left_spc = num_spc % (num_str - 1);

    for (i = k; i < text.length(); i) {
      tmp = 0;
      start = i;
      while (i < text.length() && text[i] != ' ')
        tmp++, i++;
      if (count != 0) {
        result.append(average_spc, ' ');
      }
      result.append(text.substr(start, tmp));
      count++;
      while (i < text.length() && text[i] == ' ')
        i++;
    }
    result.append(left_spc, ' ');
    return result;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();
  string text = "  this   is  a sentence ";
  solution->reorderSpaces(text);
  return 0;
}
