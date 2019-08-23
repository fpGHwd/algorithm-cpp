//
// Created by suzumiya on 8/23/19.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 5010

int W[MAXN];
int dp[MAXN][MAXN]; // dp是数量
int choose[MAXN];

int comp( const void * p, const void * q);
int main(int argc, char **argv){

    memset(dp, 0, sizeof(int) * MAXN * MAXN);
    memset(choose, 0, sizeof(int) * MAXN);

    int N, sum = 0;
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> W[i];
        sum += W[i];
    }

    qsort (W, N, sizeof(int) , comp) ;

    // sum/2
    for(int i= 1; i <= N; i++){
        for(int j = 0; j <= sum/2; j++){
            if(j<W[i])dp[i][j] = dp[i-1][j];
            else {
                if(dp[i-1][j] < dp[i-1][j-W[i]]+1){
                    choose[i]=1;
                }
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]]+ 1);
            }
        }
    }

    int chooseWeight = 0;
    for(int i = 1; i<= N; i++) {
        if (choose[i]) {
            chooseWeight += W[i];
        }
    }

    cout << abs(sum-2*chooseWeight) << " " << abs(N- 2*dp[N][sum/2]) << endl;

    return 0;
}

int comp( const void * p, const void * q)
{
    return ( * ( int * ) p - * ( int * ) q) ;
}