//
// Created by suzumiya on 9/4/19.
//


#include <climits>
#include <iostream>

#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

using  namespace std;

//改进的动态规划算法
//时间复杂度：O(kN2)
//空间复杂度：O(kN)
const int MAX_N = 100;
int findMax(int A[], int n, int k) {
    int M[MAX_N+1][MAX_N+1] = {0}; //
    int cum[MAX_N+1] = {0}; //
    for (int i = 1; i <= n; i++)
        cum[i] = cum[i-1] + A[i-1];

    for (int i = 1; i <= n; i++)
        M[i][1] = cum[i];
    for (int i = 1; i <= k; i++)
        M[1][i] = A[0];

    for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
            int best = INT_MAX;
            for (int p = 1; p <= j; p++) {
                best = min(best, max(M[p][i-1], cum[j]-cum[p]));
            }
            M[j][i] = best;
        }
    }
    return M[n][k];
}

int A[MAX_N];
int main(int argc ,char **argv){
    int m0 = 3, n0 = 9;
    int A0[] = {9,4,5,12,3,5,8,11,0};
    cout << findMax(A0, n0, m0);
/*
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << findMax(A, n, m);*/
    return 0;
}