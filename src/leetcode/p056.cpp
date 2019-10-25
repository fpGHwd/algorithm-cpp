//
// Created by Administrator on 2019/10/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> vec;
        int start, end;
        vector<vector<int>>::iterator it;
        for(it = intervals.begin(); it != intervals.end(); it++)
        {
            if(it == intervals.begin()){
                start = (*it)[0];
                end = (*it)[1];
            }else{
                if((*it)[0] > end){
                    vector<int> v;
                    v.push_back(start);v.push_back(end);
                    vec.push_back(v);
                    start = (*it)[0];end = (*it)[1];
                }else if((*it)[1] > end){ //
                    end = (*it)[1];
                }else{
                    // do nothing
                }
            }
        }

        vector<int> v1;
        v1.push_back(start);v1.push_back(end);
        vec.push_back(v1);

        return vec;
    }

    /**
     * Runtime: 72 ms, faster than 19.36% of C++ online submissions for Merge Intervals.
     * Memory Usage: 26.7 MB, less than 8.14% of C++ online submissions for Merge Intervals.
     */

};



int main()
{
    vector<vector<int>> intervals = {{5,8},{1,6},{10,12}};

    Solution *s = new Solution();
    vector<vector<int>> ret = s->merge(intervals);
    
    return 0;
}