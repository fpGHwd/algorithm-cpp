#include<stdio.h>
void binaryMiun(int s[], int n);
int abs(int a);
int main() {
    int n, i, t;
    int s[n];
    printf("输入原始数组的个数: \n");
    scanf("%d", &n);
    printf("请输入数组元素：\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &t);
        s[i] = t;
    } 
    printf("您输入的数组是:");
    for(i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    binaryMiun(s, n);
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
        printf("出列的元素是------>%d\n", s[j]);
        //将取出的元素放在元素总和较小的数组
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
        printf("原数组变为:");
        for(k = 0; k < n; k++) {
            printf("%d ", s[k]);
        }
        printf("\n");
    }
    printf("第一个数组：");
    for(i = 0; i < lcount; i++) {
        printf("%d ", l[i]);
    }
    printf("\n第二个数组：");
    for(i = 0; i < rcount; i++) {
        printf("%ld ", r[i]);
    }
    printf("\n拆分成两个数组的最小绝对值之差是：%d\n", abs(sumr-suml));
}
int abs(int a) {
    if(a < 0) 
        return -a;
    else
        return a;
}