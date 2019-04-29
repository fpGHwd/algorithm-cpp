//
// Created by suzumiya on 4/6/19.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX_LEN = 10010;
char number[MAX_LEN];
char mid[MAX_LEN];
char binary[MAX_LEN*5];
char CODE[] = {'0','1','2','3','4','5','6','7','8','9',
               'A','B','C','D','E','F','G','H','I','J',
               'K','L','M','N','O','P','Q','R','S','T',
               'U','V'};

char* int3tobin10(char *s){
    char* result = (char *)malloc(11*sizeof(char));
    int temp = 0;
    for(int i =0; i < 3; i++){
        temp = 10* temp +(s[i] - '0');
    }
    for(int i = 10-1; i>=0; i--){
        result[i] = temp%2 + '0';
        temp = temp /2;
    }
    result[10] = '\0';
    return result;
}

int binary5toint(char *s){
    int ret = 0;
    for(int i = 0; i< 5; i++){
        ret = 2 * ret + (s[i]-'0');
    }
    return ret;
}

void encode(char data[]){
    int len = strlen(data);
    int a = len %3;
    if(a){
        for(int i = 0; i<3-a; i++){
            mid[i] = '0';
        }
    }
    mid[3-a] = '\0';
    strcat(mid, data);
    a = strlen(mid);
    binary[0] = '\0';
    int len_ = strlen(mid);
    for(int i = 0; i < len_/3; i++){
        char *temp_ret = int3tobin10(mid + 3 * i);
        strcat(binary, temp_ret);
        free(temp_ret);
    }
//    printf("%d", strlen(binary));
    int len2 = strlen(binary), temp_int;
    bool print_already = false;
    for(int i = 0; i < len2/5; i++){
        temp_int = binary5toint(binary + i * 5);
        char c = CODE[temp_int];
        if(print_already == false && c == '0'){
            ; // do_nothing
        }else{
            printf("%c", CODE[temp_int]);
            print_already == true;
        }
    }
}

int main(int argc, char**argv){
    int T;
    scanf("%d", &T);
    getchar();
    for(int i = 0; i < T; i++){
        cin.getline(number, MAX_LEN);
        encode(number);
        if(i!=T){
            printf("\n");
        }
    }
    return 0;
}
