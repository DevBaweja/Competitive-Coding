#include <bits/stdc++.h>
using namespace std;

int maximizeSum(int a[], int n, int k)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 && k > 0)
        {
            a[i] = -a[i];
            k--;
        }
    }

    int sum = 0;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        mini = min(mini, a[i]);
    }

    if (k & 1)
        sum -= 2 * mini;
    return sum;
}