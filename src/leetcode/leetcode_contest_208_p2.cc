#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minOperationsMaxProfit(vector<int> &customers,
                               int boardingCost,
                               int runningCost) {
        int left = 0, i = 0, money = 0, cn, boarding;
        vector<int> vi_money;
        while (i < customers.size() || left > 0) {
            cn = left + (i < customers.size() ? customers[i] : 0);
            boarding = (cn > 4 ? 4 : cn);
            money += (boarding * boardingCost - runningCost);
            vi_money.push_back(money);
            left = cn - boarding;
            i++;
        }

        int k = 0;
        for (int j = 0; j < (int)vi_money.size(); j++) {
            if (vi_money[j] > vi_money[k])
                k = j;
        }

        if (vi_money[k] < 0)
            return -1;
        else
            return k + 1;
    }
};

int main(int argc, char *argv[]) {

    auto solution = new Solution();
    vector<int> customers = {8, 3};
    int boardingCost = 5, runningCost = 6;
    solution->minOperationsMaxProfit(customers, boardingCost,
                                     runningCost) /*method for this solution*/;

    return 0;
}
