#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(vector<int> &a)
{
    int n = a.size();
    ll cur = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        cur = max(cur + a[i], a[i] * 1ll);
        res = max(res, cur);
    }
    return res;
}
int kConcatenationMaxSum(vector<int> &a, int k)
{
    int n = a.size();
    ll mod = 1e9 + 7;
    if (k == 1)
        return kadane(a) % mod;
    ll s = 0;
    for (int e : a)
        s += e;
    vector<int> b(2 * n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
        b[i + n] = a[i];
    }
    if (s > 0)
        return (kadane(b) % mod + ((k - 2) * (s % mod)) % mod);
    return (kadane(b) % mod);
}