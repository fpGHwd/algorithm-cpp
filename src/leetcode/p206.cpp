//
// Created by suzumiya on 4/6/19.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
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

    // 递归的反转列表，递归乃正确的方向。
    ListNode* reverseList(ListNode* head) {
//        if(head->next != NULL){
//            ListNode *temp = reverseList(head->next);
//            temp->next = head;
//            head->next = NULL;
//            return head;
//        }else
//            return head;

        // recursion process:
        //      长的list
        //      短的list，包含一个尾指针// 不能返回尾指针，只能返回头指针
        //      多出来的节点
        //

        if(head == NULL)return head;

        if(head->next == NULL){
            return head; // 返回头指针
        }else{
            ListNode *temp = reverseList(head->next);
            ListNode *ln = temp;
            for(; ln->next!=NULL; ln=ln->next);
            ln->next = head;
            head->next=NULL;
            return temp;
        };
    }
};

int main(int argc, char**argv){
    // 1->2->3->4->5->NULL
    vector<int> test = {1,2,3,4,5};
    ListNode * list = NULL,  *work = NULL;


    for(auto it= test.begin(); it<test.end(); it++){
        auto temp = new ListNode(*it);
        if(work!=NULL) {
            work->next = temp;
            work=work->next;
        }
        else {
            list = temp;
            work = list;
        }
    }


    auto sl = new Solution;
    list = sl->reverseList(list);

//    cout << "OK";
    return 0;
}