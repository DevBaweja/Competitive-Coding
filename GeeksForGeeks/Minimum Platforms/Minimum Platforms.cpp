#include <bits/stdc++.h>
using namespace std;

// Sort and Merge
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0;
    int cur = 1, res = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            cur++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            cur--;
            j++;
        }
        res = max(res, cur);
    }
    return res;
}

// Using Priority Queue