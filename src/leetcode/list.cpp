//
// Created by suzumiya on 4/15/19.
//

#include "list.h"

#include <vector>
#include <cstdlib>

using namespace std;

ListNode* makeList(vector<int>& numList){
    ListNode *root =nullptr, *w = root;
    if(numList.size() == 0)
        return root;
    for(auto it= numList.begin(); it!= numList.end(); it++){
        ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
        node->val = *it;
        if(w == nullptr){w=node;root=w;}
        else {
            w->next = node;
            w=w->next;
        }
    }
    return root;
}