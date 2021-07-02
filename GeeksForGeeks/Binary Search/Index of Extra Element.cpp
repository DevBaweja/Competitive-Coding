#include <bits/stdc++.h>
using namespace std;

int findExtra(int a[], int b[], int n)
{
    int low = 0, high = n - 1;
    int res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == b[mid])
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}