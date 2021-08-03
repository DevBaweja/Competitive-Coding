#include <bits/stdc++.h>
using namespace std;

// Floor Ceil Absolute Difference

// Modified BS
int minimumDiff(vector<int> &A, int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == key)
            return A[mid];
        if (A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // element should have been in between high and low
    int mini = min(A[high] - key, key - A[low]);
    if (mini == A[high] - key)
        return A[high];
    if (mini == key - A[low])
        return A[low];
    return -1;
}