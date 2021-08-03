#include <bits/stdc++.h>
using namespace std;

// Binary Search on Answer
int bitonicPoint(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] < arr[mid]) &&
            (mid == n - 1 || arr[mid + 1] < arr[mid]))
            return arr[mid];
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            high = mid - 1;
        else if (mid < n - 1 && arr[mid + 1] > arr[mid])
            low = mid + 1;
    }
    return -1;
}