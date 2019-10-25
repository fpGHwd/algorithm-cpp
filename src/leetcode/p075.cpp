//
// Created by Administrator on 2019/10/21.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
    }
};

int main()
{
    Solution * s = new Solution();
    vector<int> vec = {2,1,2,0,1,2,1};
    s->sortColors(vec);
    for(auto it = vec.begin(); it != vec.end(); it++)
        cout << " " << *it ;
    return 0;
}