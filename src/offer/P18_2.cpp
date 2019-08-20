//
// Created by suzumiya on 8/15/19.
//

#include <cstdlib>
#include "P18_2.h"

// 删除重复的链表节点

struct ListNode{
    int val;
    ListNode * next;
};

// 删除重复节点 // 删除重复的节点--所有的节点都删除
void deleteNode (ListNode ** head);

// 1->1->2->3->3->4->5->5;
ListNode* getAList(void){
    int list[]={1,1,2,3,3,4,5,5};
    ListNode *head,*w, *pre = head;
    for(int i = 0; i < sizeof(list)/ sizeof(int); i++){
       w = (ListNode*)calloc(1, sizeof(ListNode));
       w->val = list[i];
       if(i == 0){
           head = w;
           pre = head;
       }else{
           pre->next = w;
           pre = w;
       }
    }
    return head;
}

int main(int argc, char ** argv){
    ListNode *head = getAList();
    deleteNode(&head);
    return 0;
}

void deleteNode (ListNode ** head){

    if((*head)->next == nullptr)return; // 只有一个节点直接返回

    // w值不同的那个节点, pre是值可能开始相同的第一个节点
    ListNode *w = (*head)->next,*prePre = nullptr, *pre = *head;
    // 初始化结果为空,一直更新,直到没被删除
    *head = nullptr;

    while(w!= nullptr){
        if(w->val != pre->val){ // 找到与pre值不同的节点
            if(pre->next == w){ // 如果w刚好是pre后面的节点,说明没有重复节点,pre代表的值会保留,此时如果head为空则更新head值
                if(*head == nullptr){ // 此时若head为空则更新head值
                    *head = pre;
                }
                prePre = pre;
                pre = w;
            }else{//w不是pre后面的直接节点且值不同
                // 更新prePre的后继指针
                if(prePre != nullptr){
                    prePre->next = w;
                }
                // 从pre一直删节点到w前一个节点为止
                while(pre != w){
                    ListNode * del = pre;
                    pre = pre->next;
                    delete del;
                }
            }
            w= w->next;
        }else{ // 没有找到与pre值不同的节点
            w = w->next;
        };
    }

    if(pre->next != w){
        // 从pre一直删节点到w前一个节点为止
        while(pre != w){
            ListNode * del = pre;
            pre = pre->next;
            delete del;
        }
        prePre->next = nullptr;
    }

    // 尾部的还没有处理
}
