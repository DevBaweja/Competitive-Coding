#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Sliding Window, Hashing, DP
// Rolling Hash
ll pow(int x, int k, int mod, vector<ll> &dp)
{
    if (dp[k] != -1)
        return dp[k];
    ll temp = pow(x, k / 2, mod, dp);
    if (k & 1)
        return dp[k] = ((ll)x * ((temp * temp) % mod)) % mod;
    return dp[k] = (temp * temp) % mod;
}

string subStrHash(string s, int x, int mod, int k, int hash)
{
    int n = s.size();
    vector<ll> dp(k, -1);
    dp[0] = 1;
    ll last = pow(x, k - 1, mod, dp);
    int ans = -1;
    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        ll temp = ((s[n - i - 1] - 'a' + 1) * pow(x, k - i - 1, mod, dp)) % mod;
        res = (res + temp) % mod;
    }
    if (res == hash)
        ans = n - k;

    for (int i = n - k - 1; i >= 0; i--)
    {
        ll temp = ((s[i + k] - 'a' + 1) * last) % mod;
        res = (res - temp) % mod;
        res = res < 0 ? res + mod : res;
        res = (res * x) % mod;
        res = (res + (s[i] - 'a' + 1)) % mod;
        if (res == hash)
            ans = i;
    }
    cout << ans << " ";
    return s.substr(ans, k);
}