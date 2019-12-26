#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();  
        int result = 0;  
        for(int i = 0; i < h; i++){
            for(int j  = 0; j < w; j++){
                // 0 or grid[i-1][j] right  0 or grid[i][j-1] left
                cout << "grid[i][j]:" << grid[i][j];
                if(i > 0)cout << ", grid[i-1][j]:" << grid[i-1][j];
                if(j > 0)cout << ", grid[i][j-1]:" << grid[i][j-1];
                cout << endl;
                result += (((grid[i][j] > 0)?(4*grid[i][j]+2):(0))-(i > 0?(2*(min(grid[i-1][j], grid[i][j]))):(0)) - (j > 0?(2*(min(grid[i][j-1], grid[i][j]))):(0)));
            }
        }
        return result;
    }
};

int main(int arch, char **argv){

    auto s = new Solution();
    vector<vector<int>> input = {{2,2,2},{2,1,2},{2,2,2}};
    vector<vector<int>> input1 = {{1,0},{0,2}};
    vector<vector<int>> input3 = {{1,2},{3,4}};
    cout << s->surfaceArea(input3) << endl;

    return 0;

}