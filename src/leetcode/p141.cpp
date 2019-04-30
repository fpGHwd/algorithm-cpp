//
// Created by suzumiya on 4/29/19.
//

// 如果说复杂的题都是来自于简单的题,那么其实这道题是简单题.但是也可以拿来出复杂的题目

#include <iostream>
#include <stack>
#include <cstring>
#include <map>
#include "list.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode *f = head, *b = head;
        if(!f->next || !f->next->next)return false;
        f = f->next->next;
        b = b->next;
        while (f != b) {
            if(!f->next || !f->next->next)return false;
            f = f->next->next;
            b = b->next;
        }
        return true;
    }
};

int main(int argc, char **argv) {

    return 0;
}