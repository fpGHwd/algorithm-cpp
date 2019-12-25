#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string year = date.substr(0,4);
        string month = date.substr(5,2);
        string day = date.substr(8,2);
        int yi = atoi(year.c_str()), mi = atoi(month.c_str()), di = atoi(day.c_str());
        
        int result = 0;
        for(int i = 0; i < mi-1; i++){
            result += days[i];
        }
        result += di;
        if(mi > 2)result += ((yi % 4 == 0 && yi % 100 !=0)||(yi % 400 ==0 ));

        return result;
    }
};

int main(int argc, char **argv)
{
    
    auto s = new Solution();
    string date = "2019-01-10";
    cout << s->dayOfYear(date) << endl;
    return 0;

}