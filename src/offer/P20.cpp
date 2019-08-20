//
// Created by suzumiya on 8/16/19.
//

// 表示数值的字符串

#include <iostream>
#include "P20.h"

using namespace std;

// A[.[B]][e|EC] 或者 .B[e|EC] // 这个分析方法绝了
// 数包含非指数部分和指数部分,A是非指数部分的整数部分,B是非指数部分的小数部分,C是指数部分
// 其中A是有符号的,B是无符号的小数,C是有符号的 // B的处理部分
// 有符号分为符号部分和无符号部分
// scanInteger = symbol + unsigned部分

bool isNumeric(const char * str);
void printAndJudge(char *s);
int main(int argc, char **argv){

    char *s1 = "+100", *s2 = "5e2", *s3 = "-123", *s4="3.1416", *s5 = "-1E-16";
    char *str1 = "12e+5.4", *str2 ="+-5", *str3="12e", *str4 = "1a3.14";

    printAndJudge(s1);
    printAndJudge(s2);
    printAndJudge(s3);
    printAndJudge(s4);
    printAndJudge(s5);
    printAndJudge(str1);
    printAndJudge(str2);
    printAndJudge(str3);
    printAndJudge(str4);

    return 0;
}

void printAndJudge(char *s){
    bool result = isNumeric(s);
    cout << s <<" is numeric? " << result << endl;
}


bool scanInteger(const char **str);
bool scanUnsignedInteger(const char **str);
bool isNumeric(const char * str){
    if(str == nullptr)return false;

    bool numeric = scanInteger(&str); // 全部扫描完,然后再判断,中途不会断

    if(*str =='.'){ // 这个地方的*str的歧义
        ++str;
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if(*str == 'e' || *str =='E'){
        ++str;
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0'; // numeric是过程, str是字符串现在遍历的状态,也是结果
}

bool scanUnsignedInteger(const char **str);
// 扫描有符号整数部分,包括A和C
bool scanInteger(const char **str){

    if(**str == '+' || **str == '-')
        *str = (*str) + 1;  // const char **str的特别运算,拆分需要这一部分,需要const char **这个的理解

    return scanUnsignedInteger(str);
}

// 扫描无符号整数部分,A和C
bool scanUnsignedInteger(const char **str){ // 不能修改str指向的内容

    const char * before = *str;

    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    return *str > before;
}
