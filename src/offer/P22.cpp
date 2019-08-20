//
// Created by suzumiya on 8/16/19.
//

#include <list.h>
#include <iostream>
#include "P22.h"

using namespace std;

// 链表中倒数第K个节点 // 遍历一次就可以获得那个节点 // 转化的问题
ListNode * findLastKthNode(ListNode * head, int k);
int main(int argc, char ** argv){

    cout << findLastKthNode(nullptr , 1);
    return 0;
}

ListNode * findLastKthNode(ListNode * head, int k){
    if(head == nullptr || k == 0)return nullptr;
    ListNode * fast = head, *slow = head;

    while(--k > 0 && fast != nullptr){
        fast = fast->next;
    }
    if(fast == nullptr)return nullptr;

    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}