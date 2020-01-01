#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> max = {-1,-1,-1,-1};

    string largestTimeFromDigits(vector<int>& A) {
        int used[A.size()];
        char ret[6];
        for(int i = 0; i < A.size(); i++)used[i] = 0;
        vector<int> path;
        dfs(A, path, used);
        if(max.size()==4 && max[0] != -1){
            ret[0] = max[0] + '0'; ret[1] = max[1] + '0'; ret[2] = ':',ret[3] = '0' + max[2]; ret[4] = '0' + max[3]; ret[5] = 0;
            return ret;
        }else return "";

    }

    void dfs(vector<int> & A, vector<int>& path, int used[])
    {
        if(path.size() == A.size() && validTime(path)){
            if(max.size() ==4)
            if((path[0]*1000 + path[1] *100 + path[2] * 10 + path[3]) > (max[0] * 1000 + max[1]*100+max[2] *10 + max[3])) // bool类型加括号的问题
            max.assign(path.begin(),path.end());
        }
        else
            for(int i = 0; i < A.size(); i++){
                if(used[i] ==0){
                    path.push_back(A[i]);
                    used[i] = 1;
                    dfs(A,path, used);
                    used[i] = 0;
                    path.pop_back();
                }
            }
    }

    bool validTime(vector<int> path){
        if(path.size() < 4) return false;
        if((path[0] * 10 + path[1] < 24) && (path[2] * 10 + path[3] < 60))return true;
        return false;
    }
/*
    string largestTimeFromDigits(vector<int>& A) {
        char ret[6];
        for(int i = 0; i < 6; i++)ret[i] = 0;

        sort(A.begin(), A.end()); 
        
        int used[6];
        for(int i = 0; i < 6; i++) used[i] = 0;
        // 小时10位
        int idx = 0;
        if(findLessEqualAndMax(2,A,used, ret, idx++) == false)return "";
        if(ret[0] == 2 + '0'){
            if(findLessEqualAndMax(3,A,used, ret, idx++) == false)return "";
        }else{
            if(findLessEqualAndMax(9,A,used, ret, idx++) == false)return "";
        }
        ret[idx++] = ':';
        if(findLessEqualAndMax(5,A,used, ret, idx++) == false)return "";
        if(findLessEqualAndMax(9,A,used, ret, idx++) == false)return "";
        return ret;
    }

    bool findLessEqualAndMax(int a, vector<int>& A, int used[], char ret[], int idx){
        int i = 0;
        for(i = A.size()-1; i>=0; i--){
            if(A[i] <= a  && used[i] == 0){
                used[i] = 1;
                ret[idx] = A[i] + '0';
                return true;
            }else{
                continue;
            }
        }
        return false;
    }
    */
};

int main(int arch, char **argv){
    auto s = new Solution();
    vector<int> input = {1,2,3,4};
    // 2,0,6,6 -> 06:26
    cout << s->largestTimeFromDigits(input) << endl;
    cout << (1 + 2 > 1 + 1) << endl;
    return 0;
}