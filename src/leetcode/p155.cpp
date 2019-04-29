//
// Created by suzumiya on 4/15/19.
//

// use java or c++

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> min;
public:
    /** initialize your data structure here. */

    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if(stk.size()==1){
            min.push(x);
        }else{
            if(x < min.top()){
                min.push(x);
            }else{
                min.push(min.top());
            }
        }
    }

    void pop() {
        stk.pop();
        min.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char **argv){


    return 0;
}