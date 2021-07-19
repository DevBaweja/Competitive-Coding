#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n)
{
    int incl = arr[0], excl = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = max(incl, excl);
        incl = excl + arr[i];
        excl = temp;
    }
    return max(incl, excl);
}

int FindMaxSum(int arr[], int n)
{
    vector<int> incl(n, 0);
    vector<int> excl(n, 0);
    incl[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        incl[i] = excl[i - 1] + arr[i];
        excl[i] = max(excl[i - 1], incl[i - 1]);
    }
    return max(incl[n - 1], excl[n - 1]);
}