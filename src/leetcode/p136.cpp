//
// Created by suzumiya on 4/6/19.
//

#include <vector>
#include <iostream>

using namespace std;

// 忍住不要去究竟什么cout等等的东西 // 他就是输出的因素，不要去奇迹淫巧，那都是低效率的时间。一定要多抽象。
// 抽象一定可以带你走出泥潭。不抽象和联系的时间都是没有什么用处的。就像视频里面学到的就应该是抽象而不是其他的东西呀
// 用抽象补充你的本质是细节的东西。多一点原来这个东西在数学上就是那个啊，而不是真正的现在的样子。
// 也就是达到这样的思维习惯：这个东西就是序列啊，就想计算机本质就是把信息从一个地方搬到另一个地方。没有什么区别。
// 当你在抽象上的第一反应是这个和那个（已知的东西）是一致的，那就已经比较好了。
// 所有的东西要自己去找，联系。而不是别人给你啊。
// 亦或操作就是那个操作啊
// 处理负数就要用异或。。但是如果没有负数呢？

class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        auto work = nums.begin();
        vector<int> calc(64);
        for(; work < nums.end(); work++){
            int temp = *work, i = 0;
            while(temp!=0){
                calc[i] += temp%2;
                temp = temp/2;
                i++;
            }
        }

        auto start = calc.end()-1 ;
        int result = 0 , i = 0;
        for(; start >= calc.begin(); start--){
            result = (result*2+((*start)%2));
        }
        return result;
    }


    // 不需要纠结形式，知道异或就基本上能够写出来了。
    int singleNumber(vector<int>& nums){

        auto work = nums.begin();
        int ret = 0;
        for(; work < nums.end(); work++){
            ret ^= (*(work));
        }

        return ret;
    }
};

int main(int argc, char **argv){
    vector<int> test = {4,1,2,1,2};
    auto sl = new Solution;
    cout << sl->singleNumber(test) << endl;
    return 0;
}