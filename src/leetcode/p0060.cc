#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        char ret[11]; 
        bool used[10];
        for(int i = n; i > 0 ; i--){ // 每一项
            int temp = 1 + (k-1)/factorial(i-1);
            k = k - (temp -1 ) * factorial(i-1);
            int s = 1 , j = 0;
            for(int j = 0; j < n; j++){
                if(used[j] == true){
                    continue;
                }else{
                    if(s == temp){
                        used[j] = true;
                        ret[n-i] = j + '0' + 1;
                        break;
                    }else{
                        s++;
                    }
                }
            }
        }

        ret[n] = 0;
        string retStr = ret;
        return retStr;
    }
    
    int factorial(int number)
    {	if(number<=1)
            return 1;
        else 
            return number*factorial(number-1);
    }

};

int main(int arch, char **argv){
    auto s = new Solution();
    int n = 3, k = 3;
    cout << s->getPermutation(n,k) << endl;
    return 0;
}