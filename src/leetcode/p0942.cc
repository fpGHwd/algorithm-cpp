#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> vec;
        int len = S.size(), didx= len, iidx = 0;
        for(int i = 0; i < len; i++){
            if(S[i] == 'D'){
                vec.push_back(didx--);
                if(i==len-1)vec.push_back(didx);
            }else{
                vec.push_back(iidx++);
                if(i==len-1)vec.push_back(iidx);
            }
        }
        return vec;
    }
};

int main(int arch, char **argv){

    auto s = new Solution();
    string str = "DDD",str1 = "IDID";
    s->diStringMatch(str1);

    return 0;
}