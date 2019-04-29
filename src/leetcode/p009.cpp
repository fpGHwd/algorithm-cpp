//
// Created by suzumiya on 4/10/19.
//

#include <iostream>
#include <cstring>
#include <string>


using namespace std;
class Solution {
public:

    bool isPalindrome(int x) {
        char temp[100];
        int idx = 0;
        int i = x;
        if(x < 0){
            x = -x;
            temp[idx++] = '-';
        }
        while(i){
            temp[idx++] = i%10;
            i = i/10;
        }

        bool ret = true;
        for(int j = 0; j < idx/2; j++){
            if(temp[j] != temp[idx-1-j]){
                return false;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv){
    auto sl = new Solution;
    cout <<  sl->isPalindrome(121) << endl;
    cout <<  sl->isPalindrome(-121) <<endl;
    return 0;
}