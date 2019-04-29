//
// Created by suzumiya on 4/2/19.
//

#include <iostream>

using namespace std;

void RevStr(char *src){
    char *start = src, *end = src, *ptr = src;
    while(*ptr++ != '\0'){
        if(!isalnum(*ptr)){ // ptr 单词结尾
            end = ptr-1;
            while(start < end)swap(*start++, *end--);
            start = end = ptr+1;
        }

    }
    start = src, end = ptr-2;
    while(start< end){
        swap(*start++, *end--);
    }


}

const int MAX_LEN = 1000000;
char temp[MAX_LEN]= {0};

int main(int argc, char ** argv){
    freopen("/home/suzumiya/CLionProjects/beauty-in-code/data/input", "r", stdin);

    char ch;
    int len=  0;
    while((ch = getchar())!= EOF){
        temp[len++] = ch;
    }
    temp[len] = '\0';

    RevStr(temp);

    for(int i = 0; i < len; i++){
        printf("%c", temp[i]);
    }

    fclose(stdin);

    return 0;
}

