//
// Created by suzumiya on 8/20/19.
//

#include <cstdio>
#include "P53.h"

// 找出数字在排序数组中出现的次数 = 最后出现的index - 最开始出现的index + 1

// 递归的做法
int GetFirstK(int data[], int length, int k, int start, int end)
{
    // length没有起到作用的参数,也可以存在

    if(start > end)return -1;

    int midIndex = (start + end) / 2;
    int midData = data[midIndex];

    if(midData == k){
        if((midIndex > 0 && data[midIndex-1] != k) || midIndex == 0){
            return midIndex;
        }else{
            end = midIndex -1; //
        }
    }else if(midData < k){
        start = midIndex + 1;
    }else{ // midData > k
        end = midData -1;
    }

    return GetFirstK(data, length, k, start, end); // 没有起到作用的一个参数length
    // 如果把函数和事物联系起来并且和大自然联系起来就没有什么不能理解的了 // 函数就是数学的核心
}

int GetLastK(int data[], int length, int k, int start, int end)
{

    if(start > end)return -1;

    int midIndex = (start+ end) / 2;
    int midData = data[midIndex];

    if(midData == k){
        if((midIndex < length -1 && data[midIndex + 1] != k) || midIndex == length -1){
            return midIndex;
        }else{
            start = midIndex + 1;
        }
    }else if(midData > k){
        end = midIndex -1;
    }else{ // midData < k
        start = midIndex + 1;
    }

    return GetLastK(data,length, k, start, end);
}

int GetNumberOfK(int data[], int length , int k){

    if(data == nullptr || length < 0){
        return 0;
    }

    int firstKIndex = GetFirstK(data, length, k, 0 , length-1);
    int lastKIndex = GetLastK(data, length , k , 0, length -1);

    if(firstKIndex == -1){
        return 0;
    }else{
        return lastKIndex - firstKIndex + 1;
    }
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else{
        printf("Failed. result=%d, expected= %d\n", result, expected);
    }
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
//    printf("the size of data: %d\n", sizeof(data) / sizeof(int));
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}


