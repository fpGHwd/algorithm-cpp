//
// Created by suzumiya on 4/6/19.
//

#include <iostream>
#include <cstdio>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

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
    void deleteNode(ListNode* node) {
        ListNode* w = node;
        w->val = w->next->val;
        ListNode *next = w->next;
        w->next = w->next->next;
        delete(next);
    }
};
// 知道是一个节点就好了。和是否是链表还是数组又有什么关系呢。都是一样的。记得很久之前哥哥和我说了这句话


int main(int argc, char **argv){

    printf("OK");
    return 0;
}