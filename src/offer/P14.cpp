//
// Created by suzumiya on 8/15/19.
//

#include <iostream>

using namespace std;

int maxProductAfter1(int length);
int main(int argc, char **argv){
    int length = 8;

    cout << maxProductAfter1(length);

    return 0;
}

// 动态规划的方法
int maxProductAfter1(int length){
    // 边界条件 f(1) = 1, f[0] = 0, f[2] = 2, f[3] = 3
    switch(length){
        case 0: return 0;
        case 1: return 0;
        case 2: return 1;
        case 3: return 2;
    }

    // 初始化中间矩阵 // 这个就是为了求那个矩阵的
    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3; // 这个不是很明白

    int max = 0;
    // 公式 f(i) = f(j) * f(i - j), j >= 1, i>=4
    for(int i = 4; i <= length; i++){
        for(int j = 1; j <= i/2; j++){
            int product = products[j] * products[i -j];
            if(product > max){
                max = product;
            }
            products[i] = max;
        }
    }

    // 获取最大值
//    max = products[length];

    // 释放内存
    delete[] products;

    return products[length]; // 当然这个就是结果
}

// O1时间复杂度的方法
int maxProductAfterO1(int length){

    return 0;
}