//
// Created by suzumiya on 10/2/19.
//

#include <string.h>

#include <iostream>

using namespace std;

int A[13] = {1,2,3,4,5};

char (*(*(*p)())[])();  // p: declare p as a pointer to function returning pointer to array[] of pointer to function return char  // p is a pointer to function
char (*(*x())[])(); // x: declare x as a function returning pointer to array[] of pointer to function returning char  // x is a function
void (*(*f[4])())();  // f: declare f as array of pointer to function returning pointer to function returning void  // f is pointer to array
char (*(*y[3])())[5];  // y: declare y as array[3] of pointer to function returning pointer to array[5] of char // y is pointer to array
char (*(*z)[])();  // z: declare z as a pointer to array[] of pointer to function returning char; // z is pointer to array

int main(int argc, char **argv)
{

    int (*pa)[13] = &A; // pointer to array[13] of int
    cout << (*pa)[1] << endl; // 2

    int *pa1[13] = {A, A+1};
    cout << *(pa1[0]) << endl; // 1

}