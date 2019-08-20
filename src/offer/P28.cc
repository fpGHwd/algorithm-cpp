//
// Created by suzumiya on 8/20/19.
//

#include "P28.h"
#include "P27.h"

// 判断一个二叉树是不是对称的

BinaryTreeNode* getABinaryTree(){
    BinaryTreeNode *root = new BinaryTreeNode, *temp;root->m_nValue = 8;
    temp = new BinaryTreeNode; temp->m_nValue = 6; root->m_pLeft = temp;
    temp = new BinaryTreeNode; temp->m_nValue = 10; root->m_pRight = temp;
    temp = new BinaryTreeNode; temp->m_nValue = 5; root->m_pLeft->m_pLeft = temp;
    temp = new BinaryTreeNode; temp->m_nValue = 7; root->m_pLeft->m_pRight = temp;
    temp = new BinaryTreeNode; temp->m_nValue = 9; root->m_pRight->m_pLeft = temp;
    temp = new BinaryTreeNode; temp->m_nValue = 11; root->m_pRight->m_pRight = temp;

    return root;
}

bool IsSymmetrical(BinaryTreeNode *);
int main(int argc, char**argv){



    return 0;
}

bool IsSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode* pRoot2){
    if(pRoot1->m_pLeft == nullptr && pRoot2->m_pRight == nullptr)return true;
    if(pRoot1->m_pRight == nullptr || pRoot2->m_pRight == nullptr)return false;
    if(pRoot1->m_pLeft->m_nValue != pRoot2->m_pRight->m_nValue)return false;
    else
        return IsSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
        && IsSymmetrical(pRoot1->m_pRight,pRoot2->m_pLeft); // 修改这里就可以了
}