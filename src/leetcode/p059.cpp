//
// Created by suzumiya on 4/30/19.
//


#include <vector>
#include <iostream>

using namespace std;

// 螺旋矩阵，矩阵用vector<vector<int>>来描述
// 什么语言压根都不要紧。当然其实所有的东西都是一个东西。如果这个信条已经在你的脑海里就好了。通过时间来联系的。

class Solution {
public:
//    vector<vector<int>> generateMatrix(int n){
//        // 关键载于如何 n(n^2)找到准确的vector中的位置，当然公式没有，vector也只有push_back操作。是不行的。不过可以反过来算
//        vector<vector<int>> gm;
//        for(int i = 1; i<=n; i++){ // 每一个矩阵算位置。
//            vector<int> temp;
//            for(int j = 1; j<=n; j++){
//                //对每一个位置算出数字就行
//                int round = min(min(i, j),min(n-i,n-j));
//                int round1 = round - 1;
//                int a = 4*(n-round1)*round1;
//                // i,j变数字
//                if(i==round)a+=(j-round1);
//                else if((n-j) == round1){
//                    a+= ((n-2*(round1) -1) + (i-round1));
//                }else if((n-i == round1)){
//                    a+= ((n-2*(round1) -1) * 2 + (n-(j-1)-round1));
//                }else{
//                    a+= a+= ((n-2*(round1) -1)*3 + (n-(i-1)-round1));
//                }
//                temp.push_back(a);
//            }
//            gm.push_back(temp);
//        }
//        return gm;
//    }

    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> gm;
        for(int i = 1; i<=n; i++){
            vector<int> temp;
            for(int j = 1; j<=n; j++){
                int round = min(min(i, j),min(n-i+1,n-j+1));
                int round1 = round-1;
                // int round1 = round - 1;
                int a = 4*(n-round1)*round1;
                if(i==round1+1)a+=(j-round1);
                else if((n-j) == round1){
                    a+= ((n-2*(round1) -1) + (i-round1));
                }else if((n-i == round1)){
                    a+= ((n-2*(round1) -1) * 2 + (n-(j-1)-round1));
                }else{
                    a+= ((n-2*(round1) -1)*3 + (n-(i-1)-round1));
                }
                temp.push_back(a);

            }
            gm.push_back(temp);
        }
        return gm;
    }

//    vector<vector<int>> generateMatrix(int n){
//        vector<vector<int>> gm;
//        int c= 1;
//        while(c < n*n){
//
//        }
//    }
};

int main(int argc, char **argv){

    return 0;
}