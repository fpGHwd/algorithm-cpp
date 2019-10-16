//
// Created by Administrator on 2019/10/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        int size = 1;

        // 先对vec进行排序
        sort(nums.begin(), nums.end(), less<int>());

//        for(auto itn = nums.begin(); itn != nums.end(); itn++){
//            cout << *itn;
//        }
//        cout<< endl;

        ret.push_back(nums);
        permutation(ret, nums, 0,size);
//        cout << size << endl;
        return ret;
    }

    void permutation(vector<vector<int>>& ret, vector<int>& nums, int start, int& size)
    {

        bool done = false;
        while(!done){
            vector<int>::iterator it;
            for(it = nums.end()-1; it!= nums.begin() && *(it-1) >= *it; it--);

            if(it != nums.begin()){
                done = false;
                vector<int>::iterator iter;
                for(iter = nums.end()-1; iter != (it-1) && *iter <= *(it-1);iter--);

//                cout << *(it-1) << " " << *iter << endl;

                int temp = *(it-1);
                *(it-1) = *iter;
                *iter = temp;

//                cout << *(it-1) << " " << *iter << endl;

                sort(it, nums.end(),less<int>());
//                for(auto itn = nums.begin(); itn != nums.end(); itn++){
//                    cout << *itn;
//                }
//                cout<< endl;
                ret.push_back(nums);
                size++;
            }else{
                done = true;
            }
        }
    }

    void swap(vector<int>& nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

};

// 只能用字典序来排序

int main(int argc, char **argv)
{
    vector<int> vec = {1,1,2};
    Solution* solution = new Solution();
    vector<vector<int>> ret = solution->permuteUnique(vec);

    return 0;
}