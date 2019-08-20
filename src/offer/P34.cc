//
// Created by suzumiya on 8/20/19.
//

#include <vector>
#include <iostream>
#include "P34.h"

#include "BinaryTree.h"

// 和为某一值的路径(通过根到子节点的路径) // 打印所有路径 != 判断是否有这个路径,判断路径只需要有个num就可以了

using namespace std;

void PathWithValue(vector<BinaryTreeNode*>& path, BinaryTreeNode *root, int total, int target);
void FindPath(BinaryTreeNode * root, int target){

    if(root == nullptr)return ; // 这个地方和后面的PathWithValue的root不会是空指针有联系,所以这个比较难以看出来

    int total = 0;
    vector<BinaryTreeNode*> path;
    PathWithValue(path, root, total,target);
}

void PathWithValue(vector<BinaryTreeNode*>& path, BinaryTreeNode *root, int total, int target){
/*    if(root == nullptr){
        if(*total == target){
            // print path
//            cout << "print path" << endl;
            for(vector<BinaryTreeNode*>::iterator it = path.begin(); it< path.end(); it++){
                cout << (*it)->m_nValue << ' ';
            }
            cout << endl;
        }else{
            return;
        }
    }

    if(*total < target){
        path.push_back(root);
        *total += root->m_nValue;
        if(root->m_pLeft)
            PathWithValue(path,root->m_pLeft, total,target);
        if(root->m_pRight)
            PathWithValue(path,root->m_pRight, total,target);
        *total -= root->m_nValue;
        path.pop_back();
    }else{
        return;
    }*/

// 顺序的问题
    // 确认这个地方不会出现空的指针
    total += root->m_nValue;
    path.push_back(root);

    if(root->m_pLeft == nullptr && root->m_pRight == nullptr && total == target){
        for(vector<BinaryTreeNode*>::iterator it = path.begin(); it< path.end(); it++){
            cout << (*it)->m_nValue << ' ';
        }
        cout << endl;
    }

    if(root->m_pLeft)
        PathWithValue(path,root->m_pLeft, total,target);
    if(root->m_pRight)
        PathWithValue(path,root->m_pRight, total,target);

    path.pop_back();

}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 有两条路径上的结点和为22
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 没有路径上的结点和为15
void Test2()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

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
// 有一条路径上面的结点和为15
void Test3()
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

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

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
// 没有路径上面的结点和为16
void Test4()
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

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test5()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

