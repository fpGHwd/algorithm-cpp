//
// Created by suzumiya on 8/21/19.
//

#include <cstring>
#include <cstdio>
#include "P58.h"

// 翻转字符串且不翻转其中的单词
void ReverseStr(char *start, char *end);
void ReverseSentence(char *sentence)
{
    int len = strlen(sentence);
    ReverseStr(sentence, sentence+len-1); // 整个逆置

/*    for(char *i = sentence; i < sentence + len; i++){

    }*/
    char *pBegin = sentence, *pEnd = sentence;
    while(*pBegin != '\0'){ // 不是结尾,这里比较重要 // 这里是思路最重要的地方, 关键
        if(*pBegin == ' ')
        {
            pBegin++;
            pEnd++;
        }else if(*pEnd == ' ' || *pEnd =='\0'){
            ReverseStr(pBegin, --pEnd);
            pBegin = ++pEnd;
        }else{
            pEnd++;
        }
    }
}


// 翻转单词
void ReverseStr(char *start, char *end)
{
    if(start == nullptr || end == nullptr)return;

    char tmp;
    while(start < end){
        tmp = *start;
        *start = *end;
        *end = tmp;

        start++; end--;
    }
}

// ====================测试代码====================
void Test(const char* testName, char* input, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == nullptr && expectedResult == nullptr)
       || (input != nullptr && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", nullptr, nullptr);
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", "", "");
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
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

