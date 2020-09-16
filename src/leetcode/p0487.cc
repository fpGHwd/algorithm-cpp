#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        for(int num : nums2){
            while(!s.empty() and s.top()<num)
                mp[s.top()] = num, s.pop(); // , trick
            s.push(num);
        }

        for(int &num : nums1)
            num = (mp.find(num) == mp.end()) ? -1 : mp[num];

        return nums1;
    }
};

// Input: nums1 = [2,4], nums2 = [1,2,3,4].

int main(int arch, char **argv){
    
    vector<int> nums1 = {2,4}, nums2 = {1,2,3,4};
    auto solution = new Solution();
    solution->nextGreaterElement(nums1, nums2);

    return 0;
}
