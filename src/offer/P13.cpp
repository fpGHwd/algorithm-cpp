//
// Created by suzumiya on 8/14/19.
//

#include <iostream>

using  namespace std;

int reachCategory(int m,int n, int k);
int main(){
    int k = 17;
    int m = 20, n = 20;

    cout << reachCategory(m,n,k);

    return 0;
}

void reach(int m, int n, int row, int col, int& size, int k, bool *visited);
int reachCategory(int m, int n, int k){
    bool *visited = new bool[m*n];
    int size = 0;
    reach(m,n, 0, 0,size, k, visited); // 强转
    delete[] visited;
    return size;

}

int getDigitSum(int number);
void reach(int m, int n, int row, int col, int & size, int k, bool *visited){

    // 如何处理回溯的问题

    if(row >= 0 && row < m && col >= 0 && col < n &&
            (getDigitSum(row) + getDigitSum(col) <= k) && !visited[row*n + col]){
        visited[row*n + col] = true; // 这个的意义很重要
        size++; // int & size其实等效一个外在的存储空间,大家都能用到.其实就是和全局变量的一致性啊
        // 一致性就是抽象的开始和构建更大的更方便的系统的开始吧
        reach(m, n, row+1, col, size, k, visited);
        reach(m, n, row, col+1, size, k, visited);
        reach(m, n, row-1, col, size, k, visited);
        reach(m, n, row, col-1, size, k, visited);
    }else{
        return;
    }
}

int getDigitSum(int number){
    int sum = 0;
    while(number > 0){
        sum+= number%10;
        number /= 10;
    }
    return sum;
}