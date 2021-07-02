#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n)
{
    int incl = arr[0], excl = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = max(incl, excl);
        incl = excl + arr[i];
        excl = temp;
    }
    return max(incl, excl);
}