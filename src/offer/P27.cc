//
// Created by suzumiya on 8/20/19.
//

#include "P27.h"

void MirrorRecursively(BinaryTreeNode* root);

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

int main(int argc, char **argv){
    BinaryTreeNode *root = getABinaryTree();
    MirrorRecursively(root);
    
    return 0;
}

void MirrorRecursively(BinaryTreeNode* root){
    if(root == nullptr)return;
    BinaryTreeNode *temp = root->m_pLeft;
    root->m_pLeft = root->m_pRight;
    root->m_pRight = temp;
    MirrorRecursively(root->m_pLeft);
    MirrorRecursively(root->m_pRight);

}