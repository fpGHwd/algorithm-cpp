//
// Created by suzumiya on 4/3/19.
//

#include <iostream>

using namespace std;

int cnt = 0;
int &add(int i){
    cnt =cnt + i;
    return cnt;
}

int main(void){
    int val = 1;
    cout << add(val)<<endl;

    add(val) = 3;
    cout <<add(val)<<endl;

    val = add(val);
    cout <<add(val)<<endl;

    return 0;
}