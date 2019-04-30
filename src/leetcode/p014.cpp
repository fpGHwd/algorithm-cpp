//
// Created by suzumiya on 4/30/19.
//

// 注意复用，不要为已经搞过的东西（熟练）浪费时间，copy就行了。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)return "";
        int cnt = strs.size(), idx = 0;
        string lcp = "";
//        string result = string(100,' ');
        char w;
        while(1){
            for(int i = 0; i< cnt; i++){
                if(strs[i].size() <= idx)return lcp;
                if(i==0)w = strs[i].at(idx);
                else if(strs[i].at(idx)!=w)return lcp;
            }
            lcp.append(1,w);
            idx++;
        }
    }
};

// 字符串就有字符串的操作，操作就有字符串的长度和字符串的占用空间如何处理等等的想法。这些应该是自己需要补充的。而不是需要别人会告诉你怎么做。
// 反正都是序列化，并没有什么不同的东西啊。就是序列化就是细节，细节就是实现和关键的地方。
// 序列化 -> 容易插入 = 容易实现 = 找到关键的地方。就是这么做的，每一个序列化的层次都有数字，每一层都有数字，数字都对应这着真实的意义。。。
// 不要深陷在结构里啊。
// 都是序列化，写代码就行了，然后逐渐掺入算法和数学。逐渐进去。

int main(int argc, char **argv){
//    string str = string("like");
//    string str1 = "prefix-";
//    str1.append("append");
//    cout << str1 << endl;

    return 0;
}