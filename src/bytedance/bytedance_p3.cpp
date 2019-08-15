//
// Created by suzumiya on 7/14/19.
//



#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tgmath.h>

using namespace std;

int maxScore(const vector<int>& nums){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum < 7){
        return 0;
    }
    int average = sum/7;
    if(sum%7 == 0){
        return int(pow(average,7) + 0.5);
    }else{
        int left=sum-average * 7;
        return int(pow(average,7-left) * pow(average+1,left) + 0.5);
    }
}

int main(){
    int n = 0;
    while(cin >> n){
        vector<int> ans(n,0);
        for(int i = 0; i< n; ++i){
            vector<int> nums(7,0);
            for(int j = 0; j < 7; ++j){
                cin >> nums[j];
            }
            ans[i] = maxScore(nums);
        }
        for(auto res : ans){
            cout << res << endl;
        }
    }
    return 0;
}