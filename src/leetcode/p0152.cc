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
    int maxProduct(vector<int> &A) {

        int n = A.size();
        int product = A[0];
        int maxprod = A[0];
        int minprod = A[0];
        for (int i = 1; i < n; i++) {
            int temp = maxprod;
            maxprod = max(A[i], max(maxprod * A[i], minprod * A[i]));
            minprod = min(A[i], min(minprod * A[i], temp * A[i]));
            product = max(product, maxprod);
        }

        return product;
    }
};

int main(int argc, char *argv[]) {
    auto solution = new Solution();
    vector<int> vi = {2, 3, -2, 4};
    solution->maxProduct(vi);

    return 0;
}
