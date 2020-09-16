//
// Created by suzumiya on 10/2/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

// 关于header的数量,C k&r已经讲得很好了


// register
void f(register int x, register long n)
{
    register int i;
}

int main()
{
    return 0;
}

/**
 * macro expansion
 * # 字符串拼接的作用,类型还是string
 * ## token替换,效果类似反射,获取相关的token,和函数和变量相关
 *
 * conditional inclusion
 * 利用脚本来条件头文件
 *
 * goto不过是继承了汇编的跳转特征
 *
 */