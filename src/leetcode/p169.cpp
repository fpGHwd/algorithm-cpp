//
// Created by suzumiya on 4/9/19.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// n1+n2+...+ni+...+nn= n;
// ni为众数
// 如何构造这个公式呢

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, temp;
        for(auto it = nums.begin(); it < nums.end(); it++){
            if(cnt == 0){
                temp = *it;
                cnt++;
            }else{
                if(temp == *it){
                    cnt++;
                }else {
                    cnt--;
                }
            }
        }
        return temp;
    }
};

int main(int argc, char **argv){
    vector<int> input = {2,2,1,1,1,2,2};
    auto sl = new Solution();
    cout << sl->majorityElement(input);
    return 0;
}