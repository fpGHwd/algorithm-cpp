//
// Created by suzumiya on 8/20/19.
//

#include <cstdio>
#include "P56.h"

// 数组中数字出现的次数
// 向外扩散的能力其实就是快速分类和

// 异或运算想得比较少,这个变数最多

/*void FindNumsAppearOnce(int array[], int length, int *num1, int *num2);
int[] FindNumsA(int array[], int length){
    int *res = new int[2];
    FindNumsAppearOnce(array, length, res, res+1);
}*/

void FindNumsAppearOnce(int array[], int length, int *num1, int *num2)
{
    int result = 0;
    for( int i = 0; i < length; i++){
        result ^= array[i];
    }

    int one = -1;
    for(int i = 0; i < 32; i++){
        if(result  & (0x1 << i)){
            one = i;
        }
    }

    *num1 = 0;*num2 = 0;
    for(int i = 0; i < length;i++){
        if(array[i] & (0x1 << one)){
           *num1 ^= array[i];
        }else{
            *num2 ^= array[i];
        }
    }
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
       (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = { 4, 6 };
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = { 4, 6, 1, 1, 1, 1 };
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

