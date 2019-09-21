//
// Created by suzumiya on 9/20/19.
//

#include<stdio.h>

#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

void binaryMiun(int s[], int n);
int abs(int a);
int main() {
    int n, i, t;
    int s[n];

    int k;
    scanf("%d", &k);

    for(int j = 0; j < k; j++){
        if(j !=0)printf("\n");
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &t);
            s[i] = t;
        }
        binaryMiun(s, n);
    }


    return 0;
}
void binaryMiun(int s[], int n) {
    int i, h, mid, temp, k;
    int l[n];//第一个小数组
    int r[n];//第二个小数组
    int min;
    int lcount = 0;
    int rcount = 0;
    int sum = 0;
    int suml = 0;//第一个小数组元素总和
    int sumr = 0;//第二个小数组元素的总和
    int j = 0;
    //该for循环遍历数组求元素的总和sum
    for(int i = 0; i < n; i++) {
        sum += s[i];
    }
    //mid 为元素总和的一半
    mid = sum/2;
    for(h = 0; h < n;) {
        min = mid - s[0];
        //找出离mid最近的元素
        for(i = 0; i < n; i++) {
            temp = mid - s[i];
            if(temp <= min) {
                min = temp;
                //距离mid最近的元素的下标
                j = i;
            }
        }

        if(suml <= sumr) {
            l[lcount++] = s[j];
            suml += s[j];
        }
        else {
            r[rcount++] = s[j];
            sumr += s[j];
        }
        //将刚刚在原数组取出的元素删除，更新原数组
        for(k = j; k < n; k++) {
            s[k] = s[k+1];
        }
        n--;
    }

    printf("%d %d", min(sumr,suml), max(sumr,suml));
}
int abs(int a) {
    if(a < 0)
        return -a;
    else
        return a;
}