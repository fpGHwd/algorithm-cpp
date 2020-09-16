//
// Created by suzumiya on 10/2/19.
//

#include <iostream>

using namespace std;

void exchange(int *a, int * b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 3, b = 4;
    cout << a << " " << b << endl;
    exchange(&a, &b);
    cout << a << " " << b << endl;
}