#include <bits/stdc++.h>
using namespace std;

int maxSumPath(int A[], int B[], int l1, int l2)
{
    //Your code here
    int res = 0;
    int i = 0, j = 0;
    int s1 = 0, s2 = 0;
    while (i < l1 && j < l2)
    {
        if (A[i] < B[j])
            s1 += A[i++];
        else if (A[i] > B[j])
            s2 += B[j++];
        else
        {
            int common = A[i];
            res += max(s1, s2);
            res += common;
            i++;
            j++;
            s1 = 0;
            s2 = 0;
        }
    }
    while (i < l1)
        s1 += A[i++];
    while (j < l2)
        s2 += B[j++];
    res += max(s1, s2);
    return res;
}