//
// Created by suzumiya on 4/15/19.
//
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() == 0) return 0;
            int prePrices = prices[0], ret = 0;
            for(auto it = prices.begin(); it != prices.end(); it++){
                if(*it > prePrices)ret += ((*it)-prePrices);
                prePrices = *it;
            }
            return ret;
        }
};

int main(int argc, char **argv){
    vector<int> numList = {7,1,5,3,6,4}, numList2 = {1,2,3,4,5}, numList3 = {7,6,4,3,1};
    auto sl = new Solution;

    auto profit = sl->maxProfit(numList);
    cout << profit;
    return 0;
}