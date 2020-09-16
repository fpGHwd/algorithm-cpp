#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        int ht[2001],ht_occur[2001];
        for(int i = 0; i < 2001; i++)
            ht[i]= 0;
        for(int i = 0; i < 1001; i++)
            ht_occur[i] = 0;

        for(auto i:arr)ht[i+1000]++;

        for(int i = 0; i < 2001; i++){
            if(ht[i]!=0){
              ht_occur[ht[i]]++;
            }
        }

        for(int i = 0; i < 1001; i++){
            if(ht_occur[i] != 0 && ht_occur[i]!= 1)return false;
        }

        return true;
    }
};


int main(int arch, char **argv){
    auto s = new Solution();
    vector<int> arr = {1,2,2,1,1,3};
    int result = s->uniqueOccurrences(arr);
    return 0;
}
