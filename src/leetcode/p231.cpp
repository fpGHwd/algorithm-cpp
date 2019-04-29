//
// Created by suzumiya on 4/29/19.
//

#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)return false;
        while(n){
            if(n ==1)return true;
            if(n%2!=0)return false;
            else n /=2;
        }
        return false;
    }
};

int main(int argc, char**argv){
    auto sl = new Solution();
    int input = 64;
    cout << sl->isPowerOfTwo(input);
    return 0;
}