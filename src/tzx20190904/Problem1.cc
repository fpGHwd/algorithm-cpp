//
// Created by suzumiya on 9/5/19.
//

#include <iostream>
#include <climits>
#include "Problem1.h"

using namespace std;

#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

const int max_n =  1000;

int M[max_n + 1][max_n + 1] = {0};
int sum[max_n + 1] = {0};

int min_max(int A[], int m, int k){

    for(int i = 1; i <= m; i++){
        M[1][i] = A[0];
    }

    for(int i = 2; i <= m; i++){
        sum[i] = sum[i-1] + A[i-1];
    }

    for(int i = 2; i <=m; i++){
        M[i][1] = sum[i];
    }

    for(int i = 2; i <= k; i++){
        for(int j = 2; j<= m; j++){
            int min_num = INT_MAX;
            for(int p = 1; p <= j; p++){
                min_num = min( min_num, max(M[p][i-1], sum[j] - sum[p])); // 最大和组的最小值
            }
            M[j][i] = min_num;
        }
    }

    return M[m][k];
}

int main(int argc, char **argv){

    int m0 = 3, n0 = 9;
    int A0[] = {9,4,5,12,3,5,8,11,0};
    cout << min_max(A0, n0, m0);

    return 0;

}

//  https://blog.csdn.net/littlestream9527/article/details/12242155