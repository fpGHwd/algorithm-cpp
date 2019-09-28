//
// Created by suzumiya on 9/24/19.
//

#include <iostream>

using namespace std;

union solution
{
    short a;
    char b;
};

int main()
{
    solution A;
    A.a = 0x1234;
    if(A.b == 0x12)
        cout << "max";
    if(A.b == 0x34)
        cout << "min";
}