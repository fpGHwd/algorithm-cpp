//
// Created by suzumiya on 8/20/19.
//

#include <set>
#include <vector>
#include <cstdio>
#include "P40.h"

// 找出数组中的最小的k个数 // 海量数据 = nlogk的复杂度

using namespace std;

// 平衡二叉树和红黑树是差不多的, 具有很多的共同点

/*
typedef multiset<int, greater<int> >                    intSet;
typedef multiset<int, greater<int> >::iterator          setIterator;
*/

// https://www.cnblogs.com/ficow/p/10045777.html
// greater less default的区别,结果是没有问题的

// multiset 可能有重复的元素
void GetLeastNumbers_Solution2(const vector<int>& data, multiset<int, greater<int>>& leastNumbers, int k)
{
    leastNumbers.clear();

    if(k < 1 || data.size() < k)return;

    for(vector<int>::const_iterator vit = data.begin(); vit<data.end(); vit++){ // const_iterator
        if(leastNumbers.size() < k)
            leastNumbers.insert(*vit);
        else
            if(*vit < *leastNumbers.begin()){
                leastNumbers.erase(leastNumbers.begin());
                leastNumbers.insert(*vit);
            }
    }
}

// ====================测试代码====================
void Test(char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    /*
    printf("Result for solution1:\n");
    int* output = new int[k];
    GetLeastNumbers_Solution1(data, n, output, k);
    if(expectedResult != nullptr)
    {
        for(int i = 0; i < k; ++ i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;
    */

    printf("Result for solution2:\n");
    multiset<int,greater<int>> leastNumbers;
    GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for(multiset<int, greater<int> >::iterator iter = leastNumbers.begin(); iter != leastNumbers.end(); iter++)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}