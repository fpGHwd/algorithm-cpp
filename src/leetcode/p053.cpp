//
// Created by suzumiya on 4/29/19.
//

#include <vector>
#include <iostream>

using namespace std;

//如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
//复杂度和空间还有代码中看出来，一项很重要的能力啊

// 动态规划 sum[i] = max(sum[i-1] + a[i] , a[i])

// 没有复用自己看过的书比如算法笔记，其实是一个损失



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int sum = *(nums.begin());
        int temp = *(nums.begin());
        for(auto it = nums.begin()+1; it != nums.end(); it++){
            temp = max(temp+*it, *it); // temp相当于sum[i-1]
            if(temp > sum)sum = temp;
        }
        return sum;
    }
};

int main(int argc, char **argv){
    vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};

    cout << (new Solution())->maxSubArray(test);

    return 0;
}