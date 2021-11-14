#include <bits/stdc++.h>
using namespace std;

// Time - O(n2)
// Brute Force
int maxIndexDiff(int A[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (A[j] - A[i] >= 0)
                res = max(res, j - i);
    }
    return res;
}

// Time - O(n)
// Space - O(n)
// Left and Right Prefix with Merge
int maxIndexDiff(int A[], int n)
{
    vector<int> left(n);
    left[0] = A[0];
    for (int i = 1; i < n; i++)
        left[i] = min(left[i - 1], A[i]);
    vector<int> right(n);
    right[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], A[i]);
    int res = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (left[i] <= right[j])
        {
            res = max(res, j - i);
            j++;
        }
        else
            i++;
    }
    return res;
}