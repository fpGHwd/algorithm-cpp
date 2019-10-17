//
// Created by Administrator on 2019/10/15.
//

// 原题目应该是求不一样的平方数,然后个数最少,然后如果不存在输出NAN
// n < 100000000
// 不能用O(n)复杂度

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define min(a,b)  (a>b)?b:a

#include<stdio.h>
#include<math.h>

// leetcode https://leetcode.com/problems/perfect-squares/submissions/
int numSquares(int n){

    int s= (int)sqrt(n);
    if(s * s == n)return 1;
    for(int i = 1; i <= s; i++){
        int s1 = (int)sqrt(n - i * i);
        if(s1 * s1 == n - i * i)return 2;
    }
    while(n % 4 == 0)n >>= 2;
    if((n-7)%8 == 0)return 4;
    return 3;
}

int perfect_squares_math(int n){
    int s = (int) sqrt(n);
    if (s * s == n) {
        return 1;
    }
    for (int i = 1; i * i <= n; ++i) {
        int j = (int) sqrt(n - i * i);
        if (i * i + j * j == n) {
            return 2;
        }
    }
    while ((n & 4) == 0) {      // n % 4 == 0
        n >>= 2;
    }
    if (((n - 7) & 7) == 0) {   // (n - 7) % 8 == 0
        return 4;
    }
    return 3;
}

static int dp[100000000+10];
int perfect_squares_dp(int n) {
//    int dp[n+1];
    // 最坏情况下就是本身，分解为 n 个 1
    for (int i = 1; i <= n; ++i) {
        dp[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main(int argc, char ** argv)
{
    int n;
    cin >> n;

    cout << perfect_squares_math(n) << endl;
    cout << perfect_squares_dp(n) << endl;

    return 0;
}

// n = 7时,可分解为1,1,1,4共四个
