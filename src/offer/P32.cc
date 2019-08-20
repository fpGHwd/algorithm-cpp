//
// Created by suzumiya on 8/20/19.
//

#include <deque>
#include <cstdio>
#include "BinaryTree.h"

using namespace std;

// 按行来读一个树 // 队列的层次遍历

// 核心函数是自己写的
void PrintFromTopToBottom(BinaryTreeNode *root)
{
    if(root == nullptr)return;
    deque<BinaryTreeNode* > dequeNodeList;
    dequeNodeList.push_back(root);

    BinaryTreeNode *tmp;
    while(!dequeNodeList.empty()){
        tmp = dequeNodeList.front();
        dequeNodeList.pop_front();

        printf("%d\t", tmp->m_nValue);
        if(tmp->m_pLeft)dequeNodeList.push_back(tmp->m_pLeft);
        if(tmp->m_pRight)dequeNodeList.push_back(tmp->m_pRight);
    }
}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    PrintFromTopToBottom(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

// 遍历有向图和层次遍历树都是队列(树是退化图)
