//
// Created by suzumiya on 4/29/19.
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// f(n) = f(n-1) + f(n-2)
// 缓存策略，就是递归，优化的递归
#define MAX_STAIRS 1000
int result[MAX_STAIRS];
class Solution{
public:
    int climbStairs(int n){
        if(n==1)return 1;
        if(n==2)return 2;
        if(result[n]!=0)return result[n];
        else{
            int t = climbStairs(n-1)+climbStairs(n-2);
            result[n] = t;
            return t;
        }
    }
};

int main(int argc, char **argv){
    cout << (new Solution())->climbStairs(44);
    return 0;
}