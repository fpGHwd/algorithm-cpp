#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            int square = 0, x = 0, y = 0, direction = 1;
            for(int i:commands){
                if(i==-1)direction = (4 + direction -1)%4;
                else if(i==-2)direction = (direction + 1)%4;
                else{
                    int x_tmp, y_tmp;
                    y_tmp = (y + ((direction == 1?i:0)+(direction == 3? -i:0)));
                    x_tmp = (x + ((direction == 0?i:0)+(direction == 2? -i:0)));
                    for(vector<int> v:obstacles){
                        if((direction == 1 || direction == 3) && x_tmp == v[0]){
                            // y-axis
                            if(v[1] > y && v[1] <= y_tmp)y_tmp = v[1]-1;
                            if(v[1] < y && v[1] >= y_tmp)y_tmp = v[1]+1;
                        }else if(y_tmp == v[1]){
                            // x-axis
                            if(v[0] > x && v[0] <= x_tmp)x_tmp = v[0]-1;
                            if(v[0] < x && v[0] >= x_tmp)x_tmp = v[0]+1;
                        }
                    }
                    if(x_tmp*x_tmp+y_tmp*y_tmp > square)square = x_tmp*x_tmp + y_tmp*y_tmp;
                    x = x_tmp;
                    y = y_tmp;
                }
            }
            return square;
        }
};

int main(int arch, char **argv){

    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    auto solution = new Solution();
    int ret = solution->robotSim(commands, obstacles);

    return 0;
}
