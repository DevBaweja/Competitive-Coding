#include <bits/stdc++.h>
using namespace std;

int findEquilibrium(int A[], int n)
{
    int forward[n];
    forward[0] = A[0];
    for (int i = 1; i < n; i++)
        forward[i] = forward[i - 1] + A[i];

    int backward[n];
    backward[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        backward[i] = backward[i + 1] + A[i];

    for (int i = 0; i < n; i++)
        if (forward[i] == backward[i])
            return i;
    return -1;
}
/*
int findEquilibrium(int A[], int n)
{   
    int low = 0;
    int high = 0;
    for(int i=0;i<n;i++)
        high+=A[i];
    for(int i=0;i<n;i++){
        low += A[i];
        if(low == high) return i;
        high -= A[i];
    }
        
    return -1;
}
*/