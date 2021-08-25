#include <bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int k = 2; k <= n; k++)
    {
        int val = 0;
        for (int i = 0, j = k - 1; i < k && j >= 0; i++, j--)
            val += dp[i] * dp[j];
        dp[k] = val;
    }
    return dp[n];
}