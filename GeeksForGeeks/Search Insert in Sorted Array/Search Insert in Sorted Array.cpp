#include <bits/stdc++.h>
using namespace std;

int searchInsertK(vector<int> A, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == k)
            return mid;
        if (k > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}