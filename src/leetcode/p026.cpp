//
// Created by suzumiya on 4/29/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &array) {
        if(array.size() == 0)return 0; // 对[]输入的添加
        auto pre = array.begin();
        int count = 1;
        for (auto it = array.begin(); it != array.end(); it++) {
            if (*it != *pre) {
                count++;
                *(++pre) = *it;
            }
        }
        array.erase(array.begin()+count, array.end());
        return count;
    }
};

// 突然觉得，java所有的东西都是和操作系统有关系的。为什么还要学c的系统呢。网络也是系统的一部分啊，又有什么不同。
// 世界上只有两种人，一种是相信自己的人，一种是不相信自己的人。

int main(int argc, char **argv) {

    vector<int> test = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    auto sl = new Solution();
    cout << sl->removeDuplicates(test);

    return 0;
}