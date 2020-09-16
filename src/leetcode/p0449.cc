#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());

            int count = 0,si = 0;
            for(int i:g){
                while(si < s.size() && s[si] < i)si++;
                if(si < s.size()){
                    count++;
                    si++;
                }else break;
            }
            return count;
        }
};


int main(int arch, char **argv){

    vector<int> g = {1,2,3}, s = {1,1};
    auto solution = new Solution();
    int ret = solution->findContentChildren(g, s);

    return 0;
}
