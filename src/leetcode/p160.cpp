//
// Created by suzumiya on 4/29/19.
//

// 一看这个题，就觉得是可以理解和做出来的。一定要善于联想。

#include <cmath>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *wA = headA, *wB = headB;
        while(wA){lenA++;wA = wA->next;}
        while(wB){lenB++;wB = wB->next;}
        if(lenA > lenB){
            wA = headB;
            wB = headA;
        }else{
            wA = headA; // 重置指针
            wB = headB;
        }
        int i = abs(lenA-lenB);
        while(i--)wB=wB->next;

        while(wA!=wB){
            if(wA == nullptr || wB == nullptr)return nullptr;
            wA = wA->next;
            wB = wB->next;
        }
        return wA;
    }
};


int main(int argc, char **argv) {

    return 0;
}


