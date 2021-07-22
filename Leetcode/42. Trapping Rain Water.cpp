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