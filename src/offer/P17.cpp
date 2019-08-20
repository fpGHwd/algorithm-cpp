//
// Created by suzumiya on 8/15/19.
//

#include <iostream>
#include <cstring>
#include "P17.h"

using namespace std;

bool Increment(char *str);
void Print(char *str);
int main(int argc, char ** argv){

    int len;

    // 设置长度
    cin >> len;

    // 分配空间
    char *str = new char[len + 1];
    // 初始化这个字符串
    for(int i = 0; i <= len -1; i++){
        str[i] = '0';
    }
    str[len] = '\0';

    // 检查大数是否已经是最大值,若不是则增加1返回true;若是则返回false;不关心是否已经增加
    while(!Increment(str)){
        Print(str);
    }

    //
    delete[] str;

    return 0;
}

bool Increment(char *str){
    // 大数加法

    int len = strlen(str), carry = 0;
    for(int i = len -1 ; i >= 0; i--){
        int cur = str[i] - '0' + carry;
        if(i == len -1)
            cur += 1;
        str[i] = cur%10 + '0';
        carry = cur/10;
    }
    // 这个地方因为是字符串所以比较好处理
    if(carry != 0)return true;
    else return false;
}

// 其实就是大数没有其他的,含有其他的一点字符串的处理

void Print(char *str){
    // 不打印前面的0
    int len = strlen(str), cur = 0;
    while(cur < len && str[cur] == '0' ){
        cur++;
    };

    for(int i = cur; i < len; i++){
        cout << str[i];
    }
    cout << ',';

//    cout << str[cur] << ',';
}