//
// Created by suzumiya on 10/18/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return combine1(1,n,k);
    }

    vector<vector<int>> combine1(int start, int end, int k){
        vector<vector<int>> ret;
        if(end-start+1 == k){
            vector<int> ret1;
            for(int i = start; i <= end; i++)
                ret1.push_back(i);
            ret.push_back(ret1);
            return ret;
        }
        vector<vector<int>> ret1 = combine1(start+1, end, k);
        ret.insert(ret.begin(), ret1.begin(), ret1.end());
        if(k >= 1){
            vector<vector<int>> ret2 = combine1(start+1, end, k-1);
            for(auto it = ret2.begin(); it!= ret2.end(); it++)
                (*it).push_back(start);
            ret.insert(ret.begin(), ret2.begin(), ret2.end());
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution * s = new Solution();
    vector<vector<int>> vec = s->combine(4,2);

    return 0;
}