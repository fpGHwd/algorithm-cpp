//
// Created by suzumiya on 10/20/19.
//

#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

// input "/a//b////c/d//././/.."
// output "/a/b/c/d/.."
// expect "/a/b/c"

int main(int argc, char **argv)
{
    string path;
    getline(cin, path);

    deque<string> real;
    int len = path.length();
    int i = 0,k;

    while(i < len){
        while(i < len && path[i]=='/')i++;
        k = 0;
        while(i + k < len && path[i+k] != '/')k++;
        if(i < len){
            string tmp = path.substr(i, k);
            i = i+k;
            if(tmp.compare(".") == 0){
                continue;
            }else if(tmp.compare("..") == 0){
                if(real.size() > 0)
                    real.pop_back();
            }else if(tmp.compare("") != 0){
                real.push_back(tmp);
            }
        }
    }

    string ret;
    if (real.size() == 0)ret.append("/");
    else
        for (auto it = real.begin(); it < real.end(); it = it + 1)ret.append("/"+*it);

    cout << ret;
    return 0;
}