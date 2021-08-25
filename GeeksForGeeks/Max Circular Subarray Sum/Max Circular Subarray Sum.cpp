#include <bits/stdc++.h>
using namespace std;

int circularSubarraySum(int arr[], int n)
{
    int curmax = 0;
    int curmin = 0;
    int resmax = INT_MIN;
    int resmin = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        curmax = max(arr[i], curmax + arr[i]);
        resmax = max(curmax, resmax);
        curmin = min(arr[i], curmin + arr[i]);
        resmin = min(curmin, resmin);
    }

    if (resmin == sum)
        return resmax;
    return max(resmax, sum - resmin);
}