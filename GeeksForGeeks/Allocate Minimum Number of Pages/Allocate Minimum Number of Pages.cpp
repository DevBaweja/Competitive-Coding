#include <bits/stdc++.h>
using namespace std;

bool allocatePages(int arr[], int maxi, int m, int n)
{
    int c = 1;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s > maxi)
        {
            s = arr[i];
            c++;
            if (c > m)
                return false;
        }
    }
    return true;
}

int findPages(int arr[], int n, int m)
{
    if (n < m)
        return -1;
    int low = INT_MIN;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, arr[i]);
        high += arr[i];
    }

    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (allocatePages(arr, mid, m, n))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}