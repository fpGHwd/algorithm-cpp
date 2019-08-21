//
// Created by suzumiya on 8/21/19.
//

#include <cstdio>
#include "P57_2.h"

// 连续和为s

void SequenceSum(int start, int end);
//void FindSequenceSumS(int data[], int length , int s)
void FindContinuousSequenceFault(int data[], int length , int s)
{
    if(data == nullptr || length <=1)return;

    int start = 0, end =1, currentSum = data[start] + data[end];

    while(start < end && end < length ){
        if(currentSum == s){
            SequenceSum(start,end);
        }else if(currentSum > s){
            currentSum += data[start++];
        }else{
            currentSum += data[end++];
        }
    }
}

void FindContinuousSequence(int s)
{
    int start = 1, end = 2, currentSum = start + end;

    while(start < end){
        if(currentSum == s){
            SequenceSum(start,end);
            currentSum -= start++;
        }else if(currentSum > s){
            currentSum -= start++;
        }else{
            currentSum += (++end); // 这个问题,在使用的时候一定要注意问题
        }
    }
}

void SequenceSum(int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        printf("%d",i);
        if(i != end)printf(" ");
    }
    printf("\n");
}

// ====================测试代码====================
void Test(const char* testName, int sum)
{
    if(testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum); // 题目意思理解错误
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}
