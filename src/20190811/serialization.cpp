//
// Created by suzumiya on 8/11/19.
//

#include <ostream>
#include <iostream>
#include "serialization.h"

using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int main(){
//    cout << "hello world";
    return 0;
}

/**
 * 序列化
 * @param pRoot
 * @param stream
 */
void Serialize(BinaryTreeNode *pRoot, ostream& stream){
    if(pRoot == nullptr){
        stream << "$,";
        return;
    }

    stream << pRoot->m_nValue <<",";
    Serialize(pRoot->m_pLeft,stream);
    Serialize(pRoot->m_pRight,stream);
}

/**
 * 反序列化
 * @param pRoot
 * @param stream
 */
void Deserialize(BinaryTreeNode ** pRoot, istream& stream){

}

/**
 * 读出来一个数字返回为真,否则为假
 * @param stream
 * @param number
 * @return
 */
bool ReadStream(istream& stream, int* number){
    return false;
}