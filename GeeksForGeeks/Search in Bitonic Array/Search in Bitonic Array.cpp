#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &A, int k, int l, int h, int d)
{
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (A[m] == k)
            return m;
        if ((d == 0 && A[m] < k) || (d == 1 && A[m] > k))
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int peakElement(vector<int> &A)
{
    int n = A.size();
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if ((m == 0 || A[m - 1] < A[m]) &&
            (m == n - 1 || A[m + 1] < A[m]))
            return m;
        else if (m > 0 && A[m - 1] > A[m])
            h = m - 1;
        else if (m < n - 1 && A[m + 1] > A[m])
            l = m + 1;
    }
    return -1;
}

int searchBitonic(vector<int> &A, int k)
{
    int n = A.size();
    int p = peakElement(A);
    if (p == -1)
        return binarySearch(A, k, 0, n - 1, 0);
    int l = binarySearch(A, k, 0, p - 1, 0);
    int r = binarySearch(A, k, p, n - 1, 1);
    if (l != -1)
        return l;
    if (r != -1)
        return r;
    return -1;
}