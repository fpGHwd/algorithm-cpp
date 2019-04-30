//
// Created by suzumiya on 4/29/19.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// 数组后面有空当，应该比较直观。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-- + n-- -1;
        while(m >= 0 && n >= 0){
            nums1[p--] = (nums1[m] > nums2[n])?nums1[m--]:nums2[n--];
        }
        while(n>=0){
            nums1[p--] = nums2[n--];
        }
    }
};

// 如果觉得抽象无力，那就直接看作一个数。论如何从一个数来发散到所有的东西。例如结构可以看作一个数。比如一个数组可以转换成一棵排序数。

int main(int argc, char **argv){
    vector<int> nums1 = {1,2,3,0,0,0},nums2={2,5,6};
    auto sl = new Solution();
    sl->merge(nums1,3,nums2,3);

    return 0;
}