#include <bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // Circular
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        // Peak
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        // Unsorted
        else if (arr[high] <= arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
}