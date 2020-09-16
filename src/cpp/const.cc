//
// Created by suzumiya on 9/28/19.
//

#include <iostream>

using namespace std;

static int k = 0;

void test_const_refer(const int & k)
{
//    k = 5;
}

int main(int argc, char **argv)
{

    char c = 'a';
    const char *p0 = &c;
//    *p0 = 2; // read-only variable is not assignable;
    char *const p1 = nullptr;
    int n = 5;
//    p1 = &n; // cannot assign

    test_const_refer(k);
    printf("%d\n", k);

}