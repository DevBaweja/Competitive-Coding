#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> l(n);
    l[0] = 1;
    for (int i = 1; i < n; i++)
        l[i] = l[i - 1] * nums[i - 1];
    vector<int> r(n);
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        r[i] = r[i + 1] * nums[i + 1];

    vector<int> res(n);
    res[0] = r[0];
    res[n - 1] = l[n - 1];
    for (int i = 1; i < n - 1; i++)
        res[i] = l[i] * r[i];
    return res;
}