#include <bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    int mod = 1e9 + 7;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0, j = k - 1; i < k && j >= 0; i++, j--)
        {
            dp[k] += (dp[i] * dp[j]);
            dp[k] %= mod;
        }
    }
    return dp[n];
}