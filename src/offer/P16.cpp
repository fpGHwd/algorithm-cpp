//
// Created by suzumiya on 8/15/19.
//


// 数值的整数次方
// 不用考虑大数问题

#include <iostream>

using namespace std;

double Power(double base, int exponent);
int main(int argc, char **argv){

    int exponent;
    double base;
    cin >> base >> exponent;
    cout << Power(base, exponent);

    return 0;
}

double Power(double base, int exponent){
    if(exponent == 0)return 1;
//    else if(exponent == 1) return base; // 可以不用
    double result = Power(base, exponent >> 1);
    result *= result;
    return result* ((exponent & 0x01) ? base : 1);
}