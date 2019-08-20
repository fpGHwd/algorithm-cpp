//
// Created by suzumiya on 8/15/19.
//

#include <iostream>

using namespace std;

void showBinary(int n);
int countOne(int n);
int main(int argc, char **argv){
    int n = -INT32_MIN;
    int n1= 0x80000000;
    int n2 = 0xffffffff;
    int n3 = -1;
    int n4 = -2;

    showBinary(n1);
    showBinary(n2);
    showBinary(n3);
    showBinary(n4);

    cout << (n2 == n3) << endl; // true

    cout << countOne(n3) << endl;
    cout << countOne(n4) << endl;

}

void showBinary(int n){
    for(int i = 0; i < 32 ; i++){
        cout << ((n & (0x1 << (31-i))) != 0 ? 1 : 0 ) ; // 二进制计算
    }
    cout << endl;
}

/**
 * 求1的个数和二进制过程不一样
 * @param n
 * @return
 */
int countOne(int n) {
    int count = 0;
    while(n){
        ++count;
        n = (n-1)&n; // 凝结的算法
    }
    return count;
}
