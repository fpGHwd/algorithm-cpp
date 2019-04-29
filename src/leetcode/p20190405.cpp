//
// Created by suzumiya on 4/5/19.
//

#include <cstdio>
#include <stack>

using namespace std;

static stack<char> s;

int main(int argc, char **argv){
    int n;
    scanf("%d", &n);
    getchar();
    char c;
    for(int i = 0; i < n; i++){
        scanf("%c", &c);
        if(!s.empty()){
            if(c!=s.top()){
                s.pop();
            }else{
                s.push(c);
            }
        }else{
            s.push(c);
        }
    }

    printf("%d", s.size());
    return 0;
}