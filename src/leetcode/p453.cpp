//
// Created by wd on 7/30/20.
//

#include "p453.h"
#include <string>
//#include <
#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int len = s.size();
        if(len == 0)return false;
        if(len == 1)return false;
        if(len == 2)return s[0]==s[1];

        int k;
        for(int i = 1; i <= floor(sqrt(len)); i++){

            if(len%i == 0){
                k = i;
                bool a = true;
                for(int m = 0; m < len/k; m++){
                    char c = s[m];
                    if(!a)break;
                    for(int n = m; n < len; n+=len/k){
                        if(s[n] != c){
                            a = false;
                            break;
                        }
                    }
                }

                bool b = true;
                for(int m = 0; m < k; m++){
                    char c = s[m];
                    if(!b)break;
                    for(int n = m; n < len; n+=k){
                        if(s[n] != c){
                            b = false;
                            break;
                        }
                    }
                }

                if(a || b)return true;
            }


        }

        return false;

    }
};

int main(int argc, char **argv){
    auto s = new Solution;
    string str = "zzz";
    cout << s->repeatedSubstringPattern(str);
    string s1 = "abc";
//    s1.replace(0, 1, reinterpret_cast<const char *>('c'));
    cout << s1 << endl;
}