//
// Created by suzumiya on 4/30/19.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    bool isPowerOfTwo(int n) {
//        if(n == 0)return false;
//        while(n){
//            if(n ==1)return true;
//            if(n%2!=0)return false;
//            else n /=2;
//        }
//        return false;
//    }
    int findKthLargest(vector<int>& nums, int k) {
        int max = *nums.begin(), min = max;
        for(auto & n:nums){
            if(n > max){
               max = n;
            }
            if(n < min){
                min = n;
            }
        }
        for(int i = 2; i<=k; i++){
            int temp = min;
            for(auto & n:nums){
                if(n > temp && n < max){
                    temp = n;
                }
            }
            max = temp;
        }
        return max;
    }
    // 没有考虑重复元素
};

// 尽量复用自己的时间，已经花了时间去做去想的东西都要拿来用。
// 别浪费了自己花的时间。如果你不复用，永远都是新手的状态。也永远不会有成熟的自信去面对自己和妹子。

int main(int argc, char**argv){
//    auto sl = new Solution();
//    int input = 64;
//    cout << sl->isPowerOfTwo(input);
//    return 0;
    return 0;
}