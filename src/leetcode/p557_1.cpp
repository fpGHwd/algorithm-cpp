//
// Created by suzumiya on 4/3/19.
//

#include "p557_1.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// 完全都是自己做的并没有修改，只是最后一个单词好像有点问题
string Solution::reverseWords(string s) {
    string::iterator end = s.begin(), start = s.begin();
    for (; end < s.end(); end++){
        if(*end == ' '){
            reverse(start, end);
            start = end+1;
        }
    }
    reverse(start,end); // 这个地方有点问题
    return s;
}

// lib/executable本质还是一样的 // essential time-space or cpu or function——this is an intuition
// 可以不用在emacs里面写好。做一件事情就要把所有其他时空的东西映射到现在时空的细节上来。
int main(int argc, char ** argv){
    string test = "Let's take LeetCode contest";
//    reverse(test.begin(),test.end());
    auto result("s'teL ekat edoCteeL tsetnoc");
    auto sl = new Solution;
//    sl->reverseWords(test);
    cout << sl->reverseWords(test) << endl;
    return 0;
}
// 如果说解决问题（tree-project）是主要的。那么不需要创建其他的系统。cauz full with abstract method in tree-project