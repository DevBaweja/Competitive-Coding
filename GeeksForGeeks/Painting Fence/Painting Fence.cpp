#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Tabular
ll countWays(int n, int k)
{
    if (n == 1)
        return k;
    ll mod = 1e9 + 7;
    vector<ll> dps(n + 1, -1);
    vector<ll> dpd(n + 1, -1);
    vector<ll> dpt(n + 1, -1);

    dps[1] = k;
    dpd[1] = k;
    dpt[1] = k;
    for (int i = 2; i <= n; i++)
    {
        dps[i] = dpd[i - 1];
        dpd[i] = (dpt[i - 1] * (k - 1)) % mod;
        dpt[i] = (dps[i] + dpd[i]) % mod;
    }

    return dpt[n];
}

// Tabular Space
ll countWays(int n, int k)
{
    if (n == 1)
        return k;
    ll mod = 1e9 + 7;
    vector<ll> dp(n + 1, -1);

    dp[1] = k;
    dp[2] = k * k;
    for (int i = 3; i <= n; i++)
        dp[i] = ((dp[i - 2] + dp[i - 1]) * (k - 1)) % mod;

    return dp[n];
}