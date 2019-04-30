//
// Created by suzumiya on 4/29/19.
//

#include <iostream>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

// CPP和C语言的精细来自于与机器语言的结合紧密。
// 事实上，继续要有 关键-细节 的处理方法，也要有 抽象 - 联系 的思考方法

// 不了解cpp的图就是不了解它的实现结构

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp;
        mp.insert(std::pair<char,char>('}', '{'));
        mp.insert(std::pair<char,char>(']', '['));
        mp.insert(std::pair<char,char>(')', '(')); // 储存对应信息
        int len = s.size();
        for(int i = 0; i<len;i++){
            if(s[i] == '{' ||  s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty())return false;
                if(mp[s[i]]!=st.top()) {
                    return false;
                }
                else
                    if(st.empty())return false;
                    else st.pop();
            }
        }
        if(st.empty())return true;
        else return false;
    }
};

int main(int argc, char **argv){
    string s = "{[]}";
    cout << (new Solution())->isValid(s);

    return 0;
}