//
// Created by suzumiya on 8/21/19.
//

#include <cstring>
#include <cstdio>
#include "P58_2.h"

// 翻转字符串
using namespace std;


void ReverseString(char *str, int,int);
//void RotateString(char *str, int index);
char* LeftRotateString(char *str, int index)
{
    if(str == nullptr || index > strlen(str))return nullptr;

    int len = strlen(str);
    ReverseString(str, 0, index-1);
    ReverseString(str, index, len-1);
    ReverseString(str,0, len-1); // 顺序的问题,后整个旋转

    return str;

}

// void ReverseString(char *first, char * last); // 这个函数原型更简洁
void ReverseString(char *str, int first, int last)
{
    int start = first, end = last;

    char tmp;
    while(start < end){
        tmp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = tmp;
        start++; end--;
    }
}


// ====================测试代码====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == nullptr && expectedResult == nullptr)
       || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
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

