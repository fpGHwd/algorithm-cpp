//
// Created by suzumiya on 8/14/19.
//

#include <iostream>
#include <cstring>

using namespace std;


// 为什么要分函数呢
//

bool hasPath(char* matrix, int rows, int cols, char *str);

int main(){

    // 寻找的字符串
    char *searchStr = "bfce";

    // 矩阵
    char matrix[][4] = {{'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'}};
    // 书上没有写真正的matrix所以不用纠结,还是和书上用一维表示二维比较好,下面的代码有一点歧义 matrix[row * cols + col]这里没有经过理解
    // 用的是书上一维的表现手法

    // 计算
    cout << hasPath(*matrix, 3, 4, searchStr); // ok
    
    return 0;
}

bool hasPathCore(char *matrix, int rows, int cols, int row, int col,
                 const char * str, int& pathLength, bool* visited);

bool hasPath(char* matrix, int rows, int cols, char *str){
    // 特殊判断
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr){
        return false;
    }
    // 初始化矩阵
    bool *visited = new bool[rows * cols];
    memset(visited,0,rows* cols);
    // 从每个点开始 n * n循环
    int pathLength = 0;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(hasPathCore(matrix, rows,cols,row,col, str,pathLength,visited)){
                return true;
            }
        }
    }
    delete[] visited;
    return false;

}

bool hasPathCore(char *matrix, int rows, int cols, int row, int col,
        const char * str, int& pathLength, bool* visited){
    // 如果需要匹配的str长度为0,也即str到达'\0'时,循环结束
    if(str[pathLength] == '\0'){
       return true;
    }

    // 如果找到一个匹配的字符
        // 继续寻找, 递归寻找--找到后的标记的矩阵和图本身还是一个图
        // 回溯
    bool hasPath = false;
    if(row >= 0 && row < rows && col >=0 && col < cols && matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]){
        visited[row*cols+col] = true;
        pathLength++;
        hasPath = hasPathCore(matrix, rows, cols, row+1, col, str,pathLength, visited) ||
                hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited) ||
                hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited) ||
                hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited);

        if(!hasPath){
            pathLength--;
            visited[row*cols+col] = false;
        }
    }

    return hasPath;
}

/*
bool hasPathCore(char *matrix, int rows,int cols, int row, int dol,
        const char *str, bool*visited){

        return false;
}
*/
