//
// Created by suzumiya on 4/2/19.
//

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;
int word[MAX_SIZE];

void swapStr(char *str, int len){

};

bool isConnect(){
    return false;
}

int main(int argc, char ** argv){
    freopen("/home/suzumiya/CLionProjects/beauty-in-code/data/input", "r", stdin);

    char temp[MAX_SIZE], ch;
    int len= 0;
    while((ch = getchar())!= EOF){
        temp[len++] = ch;
    }

    int idx =  len -1;
    while(idx >=0){
//        putchar(temp[idx]);
        idx--;
    }

    idx = len-1;
    int wl =0;
    while(idx >=0 ){
        if('a'<temp[idx]<'z'|| 'A'<temp[idx] <'Z'){
            if(wl!=0 && ('a'<temp[idx+1]<'z'|| 'A'<temp[idx+1] <'Z')){
                wl++;
            }else if(wl==0){
                wl++;
            }else{
                for(int i = idx+1; i < idx+len; i++){
                    putchar(temp[i]);
                }
                wl=0;
            }

        }else if( '0'<temp[idx]<'9'){
            if(wl!=0 && ('0'<temp[idx+1]<'9')){
                wl++;
            }else if(wl==0){
                wl++;
            }else{
                for(int i = idx+1; i< idx +len; i++){
                    putchar(temp[i]);
                }
                wl = 0;
            }
        }else{
            wl = 0;
            putchar(temp[idx]);
        }
        idx--;
    }

    return 0;
}