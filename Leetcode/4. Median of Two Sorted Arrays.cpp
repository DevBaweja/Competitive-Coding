#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &num1, vector<int> &num2)
{
    int n = num1.size(), m = num2.size();
    int nm = n + m;
    vector<int> res(nm);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (num1[i] < num2[j])
            res[k++] = num1[i++];
        else
            res[k++] = num2[j++];
    }
    while (i < n)
        res[k++] = num1[i++];
    while (j < m)
        res[k++] = num2[j++];
    if (nm & 1)
        return (double)res[nm / 2];
    return ((double)res[(nm - 1) / 2] + (double)res[nm / 2]) / 2;
}

// Partition
double findMedianSortedArrays(vector<int> &A, vector<int> &B)
{
    int n = A.size(), m = B.size();
    if (n > m)
    {
        swap(A, B);
        swap(n, m);
    }
    if (!n)
    {
        if (!m)
            return -1;
        if (m & 1)
            return B[m / 2];
        return ((double)B[(m - 1) / 2] + (double)B[m / 2]) / 2;
    }
    int nm = n + m;
    for (int i = 0; i <= n; i++)
    {
        int j = ((n + m + 1) / 2) - i;
        if ((i == 0 || j == m || A[i - 1] <= B[j]) && (j == 0 || i == n || B[j - 1] <= A[i]))
        {
            int left = max(i != 0 ? A[i - 1] : INT_MIN, j != 0 ? B[j - 1] : INT_MIN);
            int right = min(i != n ? A[i] : INT_MAX, j != m ? B[j] : INT_MAX);
            if (nm & 1)
                return left;
            return ((double)left + (double)right) / 2;
        }
    }
    return -1;
}

// Binary Search and Parition
double findMedianSortedArrays(vector<int> &A, vector<int> &B)
{
    int n = A.size(), m = B.size();
    if (n > m)
    {
        swap(A, B);
        swap(n, m);
    }
    if (!n)
    {
        if (!m)
            return -1;
        if (m & 1)
            return B[m / 2];
        return ((double)B[(m - 1) / 2] + (double)B[m / 2]) / 2;
    }
    int low = 0, high = n;
    int nm = n + m;
    while (low <= high)
    {
        int i = (low + high) / 2;
        int j = ((n + m + 1) / 2) - i;
        if ((i == 0 || j == m || A[i - 1] <= B[j]) && (j == 0 || i == n || B[j - 1] <= A[i]))
        {
            int left = max(i != 0 ? A[i - 1] : INT_MIN, j != 0 ? B[j - 1] : INT_MIN);
            int right = min(i != n ? A[i] : INT_MAX, j != m ? B[j] : INT_MAX);
            if (nm & 1)
                return left;
            return ((double)left + (double)right) / 2;
        }
        else if (j != 0 && i != n && B[j - 1] > A[i])
            low = i + 1;
        else if (i != 0 && j != m && A[i - 1] > B[j])
            high = i - 1;
    }
    return -1;
}