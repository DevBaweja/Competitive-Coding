#include <bits/stdc++.h>
using namespace std;

int books(int a[], int n, int k)
{
    int cur = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            cur += a[i];
            res = max(res, cur);
        }
        else
            cur = 0;
    }
    return res;
}