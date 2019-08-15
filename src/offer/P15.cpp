//
// Created by suzumiya on 8/15/19.
//

#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int i = -1;
//    cout << ( i >> 1);

    for(int i = 0; i < 32 ; i++){
        cout << ((i & (0x1 << i)) == 0 ? 1 : 0 ) << endl;
    }
}