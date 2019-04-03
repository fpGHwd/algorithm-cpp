//
// Created by suzumiya on 4/2/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int eject(vector<int>& tourist, int weight){
    if(tourist.size() <2){
        return tourist.size();
    }

    sort(tourist.begin(),tourist.end());

    if(tourist.back() <= weight /2)
        return tourist.size() %2 == 0;
    if(tourist.front() > weight /2)
        return tourist.size();
    int begin = 0, end = tourist.size() -2;
    while(tourist[end] > weight/2){
        for(int i = begin; i< end; ++i){
            if(tourist[i] + tourist[end] > weight){
                tourist.insert(tourist.begin() + end +1, tourist[i]);
                tourist.erase(tourist.begin()+i);
                end -= 2;
                begin = i;
                break;
            }
        }
        break;
    }
    int great = tourist.size() -1;
    int count = 0;
    while(great > 0 && tourist[great] + tourist[great -1] > weight){
        ++count;
        --great;
    }
    great += 1;
    if(great % 2 == 0)great/=2;
    else
        great = great/2 + 1;

    return great + count;
}

int main(int argc, char ** argv){
    int n, w;
    while(cin >> n >> w){
        if(n < 0){
            throw "n less than zero.";
        }
        vector<int> tourists(n,0);
        for(int i = 0; i < n; ++i){
            cin >> tourists[i];
        }
        int times = eject(tourists, w);
        cout << times << endl;
    }
    return 0;
}