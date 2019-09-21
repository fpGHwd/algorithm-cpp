//
// Created by suzumiya on 9/7/19.
//

#include <vector>
#include <iostream>
#include "P3.h"

using namespace std;

vector<vector<char>> candyCrush(vector<vector<char>>& board, int & result) {
    int m = board.size(), n = board[0].size();
    while (true) {
        vector<pair<int, int>> del;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 0) continue;
                int x0 = i, x1 = i, y0 = j, y1 = j;
                while (x0 >= 0 && x0 > i - 3 && board[x0][j] == board[i][j]) --x0;
                while (x1 < m && x1 < i + 3 && board[x1][j] == board[i][j]) ++x1;
                while (y0 >= 0 && y0 > j - 3 && board[i][y0] == board[i][j]) --y0;
                while (y1 < n && y1 < j + 3 && board[i][y1] == board[i][j]) ++y1;
                if (x1 - x0 > 3 || y1 - y0 > 3) del.push_back({i, j});
            }
        }
        if (del.empty()) break;
        for (auto a : del){
            board[a.first][a.second] = 0;
            result++;
        }
        for (int j = 0; j < n; ++j) {
            int t = m - 1;
            for (int i = m - 1; i >= 0; --i) {
                if (board[i][j]) swap(board[t--][j], board[i][j]);
            }
        }
    }
    return board;
}

//static int k[1000];

int main(int argc, char **argv){
    int R, C;
    char temp;
    int x1,y1,x2,y2;
    cin >> R >> C;
    vector<vector<char>> matrix;
    for(int i = 0;  i< R; i++){
        vector<char> row;
        for(int j = 0; j < C; j++){
            cin >> temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }
    cin >> x1 >> y1 >> x2 >> y2;

    int result = 0;

    temp = matrix[x1][y1];
    matrix[x1][y1] = matrix[x2][y2];
    matrix[x2][y2] = temp;

    candyCrush(matrix, result);

    cout << result;
}

// https://www.cnblogs.com/grandyang/p/7858414.html
