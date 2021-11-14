#include <bits/stdc++.h>
using namespace std;

// DP
int maxSumAfterPartitioning(vector<int> &v, int k)
{
    int n = v.size();
    if (k >= n)
        return n * (*max_element(v.begin(), v.end()));

    vector<int> dp(n, 0);
    dp[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        int res = 0;
        int maxi = 0;
        for (int j = i; j >= max(0, i - k + 1); j--)
        {
            maxi = max(maxi, v[j]);
            int prev = j ? dp[j - 1] : 0;
            int cur = prev + maxi * (i - j + 1);
            res = max(res, cur);
        }
        dp[i] = res;
    }
    return dp[n - 1];
}

// DP
int maxSumAfterPartitioning(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> dp(n, 0);
    int maxi = 0;
    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, v[i]);
        dp[i] = (i + 1) * maxi;
    }
    for (int i = k; i < n; i++)
    {
        int res = 0;
        int maxi = 0;
        for (int j = i; j >= i - k + 1; j--)
        {
            maxi = max(maxi, v[j]);
            int prev = dp[j - 1];
            int cur = prev + maxi * (i - j + 1);
            res = max(res, cur);
        }
        dp[i] = res;
    }
    return dp[n - 1];
}