//
// Created by suzumiya on 9/24/19.
//

#include <iostream>
#include <cstring>

using namespace std;

void changeContent(void){
    char a[] = "hello";
    a[0] = 'X';
    cout << a << endl;

    char *p = "world";
    *(p+0) = 'X';  // 编译器不能发现这个错误
    cout << p << endl;
}

void assignAndCompare(void)
{
    char a[10] = "hello";
    char b[10];
    strcpy(b,a);
    cout << b << endl;

    if(b==a)cout << "pointer same" << endl;
    else cout << "pointer not same" << endl;

    if(strcmp(b,a)==0)cout << "same" << endl;
    else cout << "not same" << endl;


    int len = strlen(a);
    char *p = (char*)malloc(sizeof(char) * (len+1));

    strcpy(p,a);
    if(strcmp(p,a) == 0)cout<< "P same" << endl;
    else cout << "P not same"<< endl;
}


void calculateMemory(void)
{
    char a[] = "hello world";
    char *p = a;
    cout << sizeof(a) << endl; // 12个字节
    cout << sizeof(p) << endl; // 64位有8个字节
}

int main(int argc, char **argv)
{
    // changeContent();
    // assignAndCompare();
    calculateMemory();
}