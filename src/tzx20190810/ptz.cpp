//
// Created by suzumiya on 8/10/19.
//

#include <iostream>

using namespace std;

#define MAXN 5010

int N;
int A[MAXN];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    if(N == 1){
        return 0;
    }

    if(N == 2){
        if(A[0] == A[1]){
            return 1;
        }else{
            return 0;
        }
    }

    int left = 0, right = N-1, addTotal = 0;
    int tempLeft = A[left]-1,tempRight=A[right]-1;

    while(left < right){
        if(tempLeft < tempRight){
            if(A[left] > tempLeft){
                tempLeft = A[left];
            }else{
                tempLeft++;
                addTotal += (tempLeft-A[left]);
            }
            left++;
        }else if(tempLeft > tempRight){
            if(A[right] < tempRight){
                tempRight = A[right];
            }else{
                tempRight++;
                addTotal += (tempRight - A[right]);
            }
            right--;
        }else{
            if(A[left] > tempLeft){
                tempLeft = A[left];
            }else{
                tempLeft++;
                addTotal += (tempLeft -A[left]);
            }
            left++;
            if(left < right){
                if(A[right] < tempRight){
                    tempRight = A[right];
                }else{
                    tempRight++;
                    addTotal += (tempRight - A[right]);
                }
            }
            right--;
        }

        if(right == left){
            int maxt = (tempLeft < tempRight)?tempRight:tempLeft;
            addTotal += ((A[left] < maxt)?(maxt+1-A[left]):0);
        }
    }

    printf("%d", addTotal);
    return 0;
}