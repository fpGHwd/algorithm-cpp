#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0)return 1;
        int i = 0, k = N;
        while(N){
            i++;
            N /= 2;
        }

        return floor(pow(2, (float)i)) - k -1;
    }
};

int main(int argc, char **argv)
{
    auto s = new Solution();
    int i = 10;
    cout << s->bitwiseComplement(i) << endl;
    return 0;
}