#include<stdio.h>
#include<string.h>
int n,a[500005],b[500005];
__int64 sum;
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
                b[i++]=a[q++];
            }
        }
        for(i=x;i<y;i++)a[i]=b[i];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=0;
        merge_sort(0,n);
        printf("%I64d\n",sum);
    
    return 0;
}
