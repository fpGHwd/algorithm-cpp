//
// Created by suzumiya on 8/31/19.
//

#include <iostream>
#include "TestEndian.h"

using namespace std;

bool IsBigEndian(){
    union NUM{
        int a;
        char b;
    }num;
    num.a = 0x1234;
    if( num.b == 0x12 ){
        return true;
    }
    return false;
}

int main(){

    cout << IsBigEndian(); // 是小端法,那么沿着地址增加的方向,其实是越低位,这就是小端

    return 0;
}