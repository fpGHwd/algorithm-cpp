//
// Created by suzumiya on 4/14/19.
//

#ifndef BEAUTY_IN_CODE_LIST_H
#define BEAUTY_IN_CODE_LIST_H

#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

ListNode* makeList(vector<int>& numList);

#endif //BEAUTY_IN_CODE_LIST_H
