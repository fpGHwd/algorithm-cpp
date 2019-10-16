//
// Created by suzumiya on 9/28/19.
//

#ifndef ALGORITHM_CPP_CLASSTEST_H
#define ALGORITHM_CPP_CLASSTEST_H


class ClassTest {
private:
    int a;
    static int c;
    virtual void func(int a=c);
    virtual void func_virtual()=0;
public:
    int b;
    virtual void func_private(int k = c);
};

int ClassTest::c = 0;


#endif //ALGORITHM_CPP_CLASSTEST_H
