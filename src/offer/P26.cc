//
// Created by suzumiya on 8/20/19.
//

#include <cstdlib>
#include <cstdio>
#include "P26.h"

#include "BinaryTreeNodeDouble.h"

bool HasSubstree(BinaryTreeNodeDouble* pRoot1, BinaryTreeNodeDouble* pRoot2);
int main(int argc, char **argv){
    BinaryTreeNodeDouble *n1 = nullptr, *n2= nullptr;
    printf("%d",HasSubstree(n1,n2));
    return 0;
}

bool Equal(BinaryTreeNodeDouble* n1, BinaryTreeNodeDouble* n2);
bool DoesTree1HaveTree2(BinaryTreeNodeDouble* n1, BinaryTreeNodeDouble* n2);
bool HasSubtree(BinaryTreeNodeDouble* pRoot1, BinaryTreeNodeDouble* pRoot2){
    if(pRoot1 == nullptr || pRoot2 == nullptr)return false; // 如果都为空则pRoot2只是一个空树
    bool same = false;
    if(!Equal(pRoot1,pRoot2))
        same = DoesTree1HaveTree2(pRoot1,pRoot2);

    if(!same)
        same = DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2);

    if(!same)
        same = DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2);

    return same;

}

bool DoesTreeHaveTree2(BinaryTreeNodeDouble*n1, BinaryTreeNodeDouble*n2){
    if(n2 == nullptr)return true;
    if(n1 == nullptr)return false;
    if(!Equal(n1, n2))return false;
    return DoesTree1HaveTree2(n1->m_pLeft, n2->m_pLeft) && DoesTree1HaveTree2(n1->m_pRight, n2->m_pRight);
}

bool Equal(BinaryTreeNodeDouble* n1, BinaryTreeNodeDouble* n2){
    if(abs(n1->m_dbValue-n2->m_dbValue) < 0.0000001){
        return true;
    }else{
        return false;
    }
}