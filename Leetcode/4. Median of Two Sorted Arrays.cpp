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