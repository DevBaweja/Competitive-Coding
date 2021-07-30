#include <bits/stdc++.h>
using namespace std;

// XOR
// Time- O(n)
// Space- O(1)
int search(int A[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= A[i];
    return res;
}

// Binary Search
// Time- O(log(n))
// Space- O(1)
int search(int A[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        if (low == high)
            return A[low];
        int mid = (low + high) / 2;
        if (mid % 2 == 0)
        {
            if (A[mid] == A[mid + 1])
                low = mid + 2;
            else
                high = mid;
        }
        else
        {
            if (A[mid - 1] == A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}