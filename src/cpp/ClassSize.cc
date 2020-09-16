//
// Created by suzumiya on 9/28/19.
//

#include <iostream>

using namespace std;

class A1 {}; // : //sizeof(A) = 1;
class A2 { virtual void Fun(){} }; // : sizeof(A) = 4(32位机器)/8(64位机器);
class A3 { static int a; }; // : sizeof(A) = 1;
class A4 { int a; }; // : sizeof(A) = 4;
class A5 { static int a; int b; };// : sizeof(A) = 4;

int main(int argc, char **argv)
{
    cout << sizeof(A1) << endl;
    cout << sizeof(A2) << endl;
    cout << sizeof(A3) << endl;
    cout << sizeof(A4) << endl;
    cout << sizeof(A5) << endl;
}