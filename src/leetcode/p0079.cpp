#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool backtrack(vector<vector<char>>& board, const int i, const int j, const string& word, const int pos) {
        if (pos >= word.size()) 
            return true;
        else if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())            
            return false;
        char tmp = board[i][j];
        if (tmp == '!' || tmp != word[pos])
            return false;
        board[i][j] = '!';  // mark it's been visited already
        if (backtrack(board, i - 1, j, word, pos + 1) ||
            backtrack(board, i + 1, j, word, pos + 1) ||
            backtrack(board, i, j - 1, word, pos + 1) ||
            backtrack(board, i, j + 1, word, pos + 1))
            return true;
        board[i][j] = tmp;  // get the value back before returning to previous node
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.size() == 0) return false;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (backtrack(board, i, j, word, 0))
                    return true;
        return false;
    }
};

int main(){
    vector<vector<char>> vvc;
    string s;
    auto solution = new Solution();
    cout << solution->exist(vvc, s) << endl;
    printf("%s\n", "234234");
    return 0;
}
