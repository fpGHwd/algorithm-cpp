//
// Created by suzumiya on 9/28/19.
//

#include <iostream>

using namespace std;

struct AlignData1
{
    char c;
    short b;
    int i;
    char d;
}Node; // 12 bytes

struct AlignData2
{
    char c;
    char d;
    short b;
    int i;
}Node2; // 8 bytes


class Base1{
    virtual void fun1(){}
    virtual void fun11(){}
public:
    virtual ~Base1();
}; // 4(32位)  8(64位)

class Base1Member{
    virtual void fun1(){}
    virtual void fun11(){}
public:
    char a;
    short b;
    int c;
    virtual ~Base1Member();
}; // 4(32位)  8(64位) + 8 = 16字节

class Base2{
    virtual void fun2(){}
}; // 4

class DerivedFromOne: public Base2
{
    virtual void fun2(){}
    virtual void fun22(){}
}; // 4

class DerivedFromTwo: public Base1, public Base2
{
    virtual void fun3(){}
}; // 8(32位) 16((64位)


union U1
{
    int n;
    char s[11];
    double d;
};
// 容纳最宽的成员；大小被其包含的所有基本数据类型大小所整除

union U2
{
    int n;
    char s[5];
    double d;
};  //8

int main(int argc, char **argv)
{
    cout << sizeof(AlignData1) << endl;
    cout << sizeof(AlignData2) << endl;

    cout << "sizeof Base1 " << sizeof(Base1) << endl;
    cout << "sizeof Base2 " << sizeof(Base2) << endl;
    cout << "sizeof FromOne " << sizeof(DerivedFromOne) << endl;
    cout << "sizeof FromTwo " << sizeof(DerivedFromTwo) << endl;

    cout << "sizeof Base1Member " << sizeof(Base1Member) << endl; // 16字节


    // union
    cout << "sizeof union U1 " << sizeof(U1) << endl;
    cout << "sizeof union U2 " << sizeof(U2) << endl;
}