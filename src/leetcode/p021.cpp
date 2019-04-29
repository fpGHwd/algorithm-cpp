//
// Created by suzumiya on 4/14/19.
//

#include <cstdio>
#include "list.h"
//#include <list>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>

using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *p, *w;
        if(p1 == nullptr){
            return p2;
        }else if(p2 == nullptr){
            return p1;
        }
        if(p1->val <= p2->val){
            p = p1;
            p1 = p1->next;
        }else{
            p = p2;
            p2 = p2->next;
        }
        w = p;
        while(p1!= nullptr && p2!= nullptr){
            if(p1->val <= p2->val){
                w->next = p1;
                p1 = p1->next;
            }else{
                w->next = p2;
                p2 = p2->next;
            }
            w = w->next;
        }
        if(p1 != nullptr){
            w->next = p1;
        }
        if(p2 != nullptr){
            w->next = p2;
        }
        return p;
    }
};

// C语言的递归也比较容易理解，比较容易写。代码越少的函数越容易写。

int main(int argc, char **argv){
    vector<int> numList1 = {1,2,4}, numList2 = {1,3,4};
    auto sl = new Solution();
    auto *l1 = makeList(numList1), *l2 = makeList(numList2);
    auto *p = sl->mergeTwoLists(l1, l2);
    return 0;
}