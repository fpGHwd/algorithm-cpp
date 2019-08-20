//
// Created by suzumiya on 8/20/19.
//

#include "variables.h"

/* 作者：独酌逸醉
 * 时间：2012.08.18
 * 功能：用C语言实现变长参数小例：求和
 * IDE:  Microsoft Visual Studio 2010
 */

#include <stdio.h>
#include <stdarg.h>

#define END -1

int va_sum (int first_num, ...)
{
    // (1) 定义参数列表
    va_list ap;
    // (2) 初始化参数列表
    va_start(ap, first_num); // start初始化参数为参数列表,后面直接处理ap

    int result = first_num;
    int temp = 0;
    // 获取参数值
    while ((temp = va_arg(ap, int)) != END)  // arg相当于取实际的参数值
    {
        result += temp;
    }

    // 关闭参数列表
    va_end(ap);

    return result;
}

int main ()
{
    int sum_val = va_sum(1, 2, 3, 4, 5, END);
    printf ("%d", sum_val);
    return 0;
}