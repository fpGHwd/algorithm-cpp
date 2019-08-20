//
// Created by suzumiya on 8/20/19.
//

#include <cstdio>
#include "Test.h"

using  namespace std;

struct TestStruct{
    int i;
    char str[0];
};

int main(int argc, char **argv){

    TestStruct * ptr = nullptr;

    printf("%x\n", ptr);
    printf("%x\n", ptr->i); // interrupted by signal 11: SIGSEGV
    printf("%x\n", ptr->str);


    return 0;
}