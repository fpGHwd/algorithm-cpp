//
// Created by suzumiya on 9/24/19.
//

#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    char str[10] = "Wha\0t?";
    int m = strlen(str);  // 获取对象的字符串长度 3
    int n = sizeof(str);  // 获取对象的字节大小 7

    cout << m << endl << n;
}