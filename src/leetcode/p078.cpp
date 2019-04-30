//
// Created by suzumiya on 4/30/19.
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// 什么和幂集有关系，从数学上去想会很容易的。

// 什么copy和初始化都从序列化和数字上去想。

// 说道集，当然是集合。实现是另外一件事情了。
// 数学是确定性的，也就是，用其他人的时空来换取这种确定性。
// 所以所有的东西都不是免费的。
// 但是对于不用数学的人，其实也并没有什么两样。

// 求幂集的思路，其实以前的思考并不是完全没有用。只是没有联系起来——即序列化——都是孤立的想法。
// 每一种思路也并不是孤立的。只有联系起来，才有理解的感觉。如果不联系，内心就会觉得不理解。


// 就是把一个数组转化成集合组（幂集）

// 遇上一个数就把已有的子集加上作为新的子集。

// 反正都是一个序列在做同样的事情，为什么。就没有不同的东西。为什么不只用java呢。java转C那就是另一件事情了。
// malloc只是std::vector的一部分而已。
// 所以放弃c++用java吧。我不要。
//

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ss;
        ss.push_back({});
        int len = nums.size();
        int size = pow(2, len);
        for(int set = 1; set < size; set++){
            vector<int> temp;
            int k = 0;
            while(k < len){
                if((1<<k) & set){
                    temp.push_back(nums[k]);
                }
                k++;
            }
            ss.push_back(temp);
        }
        return ss;
    }
};

int main(int argc, char **argv) {
    vector<int> test = {1,2,3};
    auto ss = (new Solution())->subsets(test);
    cout << ss.size() << endl;
    return 0;
}