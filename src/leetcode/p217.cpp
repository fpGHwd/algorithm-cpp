//
// Created by suzumiya on 4/29/19.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto s = new set<int>;
        for(auto it = nums.begin(); it!= nums.end(); it++){
            if(s->find(*it)!=s->end()){
                return true;
            }else{
                s->insert(*it);
            }
        }
        return false;
    }
};

int main(int argc, char **argv){

    return 0;
}