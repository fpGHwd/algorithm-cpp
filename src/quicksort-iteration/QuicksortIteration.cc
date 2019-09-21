//
// Created by suzumiya on 8/29/19.
//

#include <stack>
#include "QuicksortIteration.h"

using namespace std;

int partition(int * a, int left, int right)
{
    if( a == nullptr || left <0 || right < 0 || left >= right)return -1; // condition
    int pivot = a[left];

    while(left < right){
        while(left < right && a[right] >= pivot)right--;
        if(left < right)a[left] = a[right];
        while(left < right && a[left] <= pivot)left++; // last a occupation
        if(left < right)a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}

void QuickSortIteration(int *a, int left, int right)
{
    // condition
    if( a == nullptr || left <0 || right < 0 || left >= right)return;

    stack<int> temp;
    temp.push(right);
    temp.push(left);

    int i, j;
    while(!temp.empty()){
        i = temp.top();temp.pop();
        j = temp.top();temp.pop();

        int p = partition(a, i, j);
        if(p-1 > i){ // p > i -> p > left -> p-1 > i
            temp.push(p-1);
            temp.push(i);
        }
        if( p+1 < j){ // p < j -> p < right -> p+1 < j
            temp.push(j);
            temp.push(p+1);
        }
    }
}

int main(){
    // test
    int a[] = {7,3,9,1,2,6,8,4,0,5}, left = 0, right = 9;
    QuickSortIteration(a,left,right);

    return 0;
}