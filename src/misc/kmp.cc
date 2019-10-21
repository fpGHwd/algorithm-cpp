//
// Created by suzumiya on 10/20/19.
//
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


int* table(char* str)
{
//    vector<int> vec;
//    int ret[strlen(str)];

    int * ret = (int *)malloc(sizeof(int) * strlen(str));

//    vec.push_back(-1);
//    vec.push_back(0);
    int pos = 0, cnd = 0;
    ret[pos++] = -1; ret[pos++] = 0;

    while(pos < strlen(str)){
        if(str[pos-1] == str[cnd]){
            ret[pos++] = ++cnd;
        }else if(cnd > 0){
            cnd = ret[cnd];
        }else{ // cnd = 0
            ret[pos++] = 0;
        }
    }

    return ret;
}

int main(int argc, char ** argv)
{
    char *test = "ABCDABD";

//    vector<int> vec = table(test);
    int * ret = table(test);

    for(int i = 0; i < strlen(test); i++){
        cout << " " << ret[i] ;
    }

    return 0;
}