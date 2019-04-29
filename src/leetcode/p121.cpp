//
// Created by suzumiya on 4/15/19.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
//        if(prices.size() == 0)return 0;
//        int ret = 0, prePrice, max = 0;
//        for(auto it = prices.begin(); it < prices.end(); it++){
//            if(it==prices.begin())prePrice=*it;
//            else{
//                if(*it > prePrice){
//                    ret += (*it-prePrice);
//                    if(ret > max)max = ret;
//                }else{
//                    ret = 0;
//                }
//                prePrice = *it;
//            }
//        }
//        return max;
        if(prices.size() == 0)return 0;
        int min = prices[0], max = 0;
        for(auto it = prices.begin()+1; it != prices.end(); it++){
            if(*it - min > max)max = *it-min;
            if(*it < min)min = *it;
        }
        return max;
    }
};

int main(int argc, char **argv){
    vector<int> numList = {7,1,5,3,6,4}, numList1 = {7,6,4,3,1};
    auto sl = new Solution();
    cout << sl->maxProfit(numList1);
    return 0;
}