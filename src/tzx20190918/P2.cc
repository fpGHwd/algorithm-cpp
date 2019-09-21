//
// Created by suzumiya on 9/18/19.
//

#include "P2.h"

#include <iostream>
#include <vector>
using namespace std;

int power(int n)
{
    int ans = 1;
    for(int i = 0; i < n; i++)
        ans *=2;
    return ans;
}

vector<int> doOR(vector<int> &A)
{
    if(A.size() == 1) return A;
    vector<int> nums;
    for (int i = 0; i < A.size()/2; i++)
    {
        nums.push_back(A[2*i]|A[2*i+1]);
    }
    return nums;
}

vector<int> doXOR(vector<int> &A)
{
    if(A.size() == 1) return A;
    vector<int> nums;
    for (int i = 0; i < A.size()/2; i++)
    {
        nums.push_back(A[2*i]^A[2*i+1]);
    }
    return nums;
}

int main()
{
    int n, m;
    cin>>n>>m;
    int len = power(n);
    vector<int> A(len, 0);
    for (int i = 0; i < len; i++)
        cin>>A[i];

    int ans;

//    for (int j = 0; j < m; j++)
//    {
//        int index, value;
//        cin>>index>>value;
//
//        A[index-1] = value;
//
//        for(int )

        int times = n/2*2;

        vector<int> tmp_last = A;
        vector<int> tmp_or, tmp_xor;
        for (int k = 0; k < times/2; k++)
        {
            tmp_or = doOR(tmp_last);
            tmp_xor = doXOR(tmp_or);
        }

        if (n == times)
        {
            ans = tmp_xor[0];
        }
        else
        {
            vector<int> nums = doOR(tmp_xor);
            ans = nums[0];
        }
//        cout<<ans<<endl;
//    }

    for( int i = 0; i< m; i++){
        int index, value;
        cin >> index >> value;
        int a = A[index] ^ (index%2 ==0?A[index+1]:A[index-1]);
        int b  = value ^ (index%2 ==0?A[index+1]:A[index-1]);
        cout << (ans ^ a ^ b);
    }

    return 0;
}