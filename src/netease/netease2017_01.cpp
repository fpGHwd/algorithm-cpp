//
// Created by suzumiya on 3/31/19.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

// https://blog.csdn.net/u010732356/article/details/65970931
// n cores, processing = 1k/s, tasks[n], require length
// tasks[n] = A[a] + B[b] while a + b = n
// A[a] < B[b] and max(A[a])
// time[i][s] = max(time[i-1][s], time[i-1][s-v[i]] + v[i]) while s = taskSize

const int A = 210000;
int dp[A];

int netease(int argc, char ** argv){

    freopen("/home/suzumiya/CLionProjects/beauty-in-code/data/input", "r", stdin);

    int n, task[A] ,sum = 0,temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        task[i] = temp/1024;
        sum += temp/1024;
    }

    for(int i = 0 ; i < n ; i ++)
        for(int j = sum/2 ; j >= task[i] ; --j)
            dp[j] = max(dp[j],dp[j-task[i]]+task[i]);

    printf("%d\n",(sum-dp[sum/2])*1024);

    fclose(stdin);
    return 0;
}