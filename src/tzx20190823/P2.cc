//
// Created by suzumiya on 8/23/19.
//

#include <iostream>
#include "P2.h"

using  namespace std;

#define MIN(a,b) (a>b?b:a)

int main(int argc, char **argv){

    long n, m;
    cin >> n >> m;

    long result = 0;
    long num, vol;
    for( int i = 0; i < n; i++){
        cin >> num >> vol;
        result = result + (MIN(m/vol, num));
        m -= (MIN(m/vol, num)) * vol;
    }
    printf("%lld", result);

    return 0;
}
