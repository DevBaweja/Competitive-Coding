#include <bits/stdc++.h>
using namespace std;

// Prefix and Suffix Array
int trap(vector<int> &height)
{
    int n = height.size();
    if (!n)
        return 0;
    vector<int> l(n);
    vector<int> r(n);

    l[0] = height[0];
    for (int i = 1; i < n; i++)
        l[i] = max(l[i - 1], height[i]);

    r[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        r[i] = max(r[i + 1], height[i]);

    int count = 0;
    for (int i = 0; i < n; i++)
        count += min(l[i], r[i]) - height[i];
    return count;
}

// Two Pointers
int trappingWater(int a[], int n)
{
    int l = 0, r = n - 1;
    int lm = 0, rm = 0;
    int c = 0;
    while (l <= r)
    {
        if (a[l] <= a[r])
        {
            if (a[l] >= lm)
                lm = a[l];
            else
                c += lm - a[l];
            l++;
        }
        else
        {
            if (a[r] >= rm)
                rm = a[r];
            else
                c += rm - a[r];
            r--;
        }
    }
    return c;
}