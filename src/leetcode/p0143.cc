#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    vector<ListNode *> vln;
    for (ListNode *ln = head; ln; ln = ln->next) {
      vln.push_back(ln);
    }

    ListNode *tmp;
    int k = vln.size();
    for (int i = 0; i < k - i; i++) {
      if (i + i + 1 != k) {
        tmp->next = vln[i];
        vln[i]->next = vln[k - 1 - i];
        tmp = vln[k - 1 - i];
      } else {
        tmp->next = vln[i];
        tmp = tmp->next;
      }
    }
    tmp->next = nullptr;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  ListNode *root = new ListNode(1);

  root->next = new ListNode(2);
  root->next->next = new ListNode(3);
  root->next->next->next = new ListNode(4);

  solution->reorderList(root);

  return 0;
}
