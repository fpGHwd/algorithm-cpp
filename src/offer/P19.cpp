//
// Created by suzumiya on 8/15/19.
//

#include <iostream>
#include "P19.h"

// 正则表达式匹配
// 匹配

// String
// ba*ab

using namespace std;

// 这个题很难，但是有意思，还是没有找到重要的那个点

bool match(char* str, char *pattern);
int main(int argc, char **argv){
    char *str_1 = "bb";
    char *str0 = "bab";
    char *str1 = "baab";
    char *str2 = "baaab";
    char *pattern = "ba*ab";

    cout << match(str1,pattern);
    return 0;
}

bool matchCore(char *str, char *pattern); // another layer
bool match(char* str, char *pattern){
    if(str == nullptr || pattern == nullptr)return false;

    return matchCore(str, pattern);
}

bool matchCore(char *str, char *pattern){
    if(*str == '\0' && *pattern == '\0')return true;

    if(*(pattern+1) == '*'){
        if(*pattern == *str || (*pattern == '.' && *str!='\0')){ //.*形式的pattern
            return matchCore(str, pattern+2)  // 匹配0次
            || matchCore(str+1,pattern+2) // 匹配1次
            || matchCore(str+1, pattern); // 匹配至少1次
        }else{
            return matchCore(str, pattern+2); // 匹配0次
        }
    }

    if(*str == *pattern ||  (*pattern == '.' && *str!='\0')){
        return matchCore(str+1, pattern + 1);
    }
    return false;
}