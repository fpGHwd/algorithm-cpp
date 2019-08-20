//
// Created by suzumiya on 8/16/19.
//

#include <cstdio>
#include "ConstP.h"

using namespace std;

int main(){
    char greeting[] = "hello";
    const char * p = greeting;
    greeting[0] = 'm';
//    p[0] = "b"; // read-only variable is not assignable
    printf("%s\n", p); // mello
}