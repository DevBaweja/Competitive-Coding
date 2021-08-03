#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canTime(int arr[], int n, int k, ll maxi)
{
    ll sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            return false;
        sum += arr[i];
        if (sum > maxi)
        {
            sum = arr[i];
            count++;
            if (count > k)
                return false;
        }
    }
    return true;
}

ll minTime(int arr[], int n, int k)
{
    ll low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, arr[i] * 1ll);
        high += arr[i];
    }
    ll res = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (canTime(arr, n, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}