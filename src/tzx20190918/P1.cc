//
// Created by suzumiya on 9/18/19.
//

#include "P1.h"

#include <iostream>
#include <vector>

using namespace std;

#define max(a,b) (a>b?a:b)

long playGames(vector<int> cost)
{
    int max = 0;
    for(auto it=cost.begin(); it!=cost.end(); it++){
        max = max(*it, max);
    }
    long l = 0, r = max * 2;
    while(l < r){
        long m = (l+r )/2;
        long cnt = 0;
        for(auto it = cost.begin();it !=cost.end(); it++){
            cnt+=max(m-*it,0);
        }
        if(m > cnt)
            l = m +1;
        else
            r = m;
    }
    return max(l,max);
}

int main(int argc, char **argv){
    vector<int> role_player;
    int n, temp;
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> temp;
        role_player.push_back(temp);
    }

    cout << playGames(role_player);
}
