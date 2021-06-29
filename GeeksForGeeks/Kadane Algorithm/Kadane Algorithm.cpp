#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int cur = arr[0], res = arr[0];
    for (int i = 1; i < n; i++)
    {
        cur = max(arr[i], cur + arr[i]);
        res = max(res, cur);
    }
    return res;
}