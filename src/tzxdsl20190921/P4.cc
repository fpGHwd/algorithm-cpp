//
// Created by suzumiya on 9/21/19.
//

#include "P4.h"


#include<stdio.h>
#include<string.h>
#include <cmath>

int n,a[100005],b[100005];
long sum;
long sumT = 0;

using namespace std;

void merge_sort(int x,int y)
{
    if(y-x>1)
    {
        int m=x+(y-x)/2;
        int p=x,q=m,i=x;
        merge_sort(x,m);
        merge_sort(m,y);
        while(p<m||q<y)
        {
            if(q>=y||(p<m&&a[p]<=a[q]))
                b[i++]=a[p++];
            else
            {
                sum+=m-p;
                for(int i = 0;  i < m-p; i++){
                    // 求和
                    sumT += abs(a[q]-a[p]);
                }
                b[i++]=a[q++];
            }
        }
        for(i=x;i<y;i++){
            a[i]=b[i];
        }
    }
}
int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum=0;
    merge_sort(0,n);
    printf("%lld\n",sumT);
    return 0;
}
