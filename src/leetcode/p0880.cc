#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     vector<string> uncommonFromSentences(string A, string B) {
//         set<string> set;
//         int start, end;
//         for(end = start = 0; end <= A.length(); end++){
//             if(A[end]==' ' || (end == A.length() && end != start)){
//                 set.insert(A.substr(start, end-start));
//                 start = end+1;

//             }
//         }

//         vector<string> ret;
//         for(end = start = 0; end <= B.length(); end++){
//             if(B[end] == ' ' || (end == B.length() && end != start)){
//                 if(set.find(B.substr(start, end-start))!= set.end()){
//                     set.erase(set.find(B.substr(start,end-start)));
//                 }else{
//                     ret.push_back(B.substr(start,end-start));
//                 }
//                 start = end+1;
//             }
//         }

//         for(auto it:set){
//             ret.push_back(it);
//         }
//         return ret;
//     }
// };
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {

        unordered_map<string, int> map;

        int start, end;
        for(end = start = 0; end <= A.length(); end++){
            if(A[end]== ' ' || (end == A.length() && end != start)){
                map[A.substr(start, end-start)]++;
                start = end + 1;
            }
        }

        vector<string> ret;
        for(end = start = 0; end <= B.length(); end++){
            if(B[end] == ' ' || (end == B.length() && end != start)){
                map[B.substr(start, end-start)]++;
                start = end+1;
            }
        }

        for(auto it:map){
            if(it.second == 1)
                ret.push_back(it.first);
        }
        return ret;
    }
};


int main(int arch, char **argv){

    string A = "this apple is sweet", B = "this apple is sour";
    auto s = new Solution();
    vector<string> result = s->uncommonFromSentences(A, B);

    return 0;
}
