#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (!arr[mid])
        return binarySearch(arr, mid + 1, high);
    if (arr[mid])
    {
        if (mid == 0 || (mid > 0 && arr[mid - 1] == 0))
            return mid;
        return binarySearch(arr, low, mid - 1);
    }
}

int transitionPoint(int arr[], int n)
{
    return binarySearch(arr, 0, n - 1);
}