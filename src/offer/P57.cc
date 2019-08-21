//
// Created by suzumiya on 8/21/19.
//

#include <cstdlib>
#include <cstdio>
#include "P57.h"

// 和为S的数字
// 普通解法为什么是n^2的复杂度
// 排序双指针的复杂度 nlogn 复杂度

using namespace std;

int comp(const void *p, const void *q);
bool FindNumbersWithSum(int data[], int length, int s, int *num1, int *num2 )
{
    qsort(data, length,sizeof(int),comp);
    int left = 0, right = length -1;
    while(left < right){
        if(data[left] + data[right] == s){
            *num1 = data[left];
            *num2 = data[right];
//            left++;right++; // 需要指示结果是否是想要的 // 用bool类型而不是int类型更好一点
            return true;
        }else if(data[left] + data[right] >s){
            right--;
        }else{
            left++;
        }
    }
    return false;
}

int comp(const void *p, const void *q)
{
    return (*(int*)p) - (*(int*)q);
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int num1, num2;
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if(result == expectedReturn)
    {
        if(result)
        {
            if(num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("FAILED. \n");
        }
        else
            printf("Passed. \n");
    }
    else
        printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

