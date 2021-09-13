#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, int n, int A[])
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; i++)
    {
        int maxi = INT_MIN;
        for (int j = 2; j <= n; j++)
        {
            maxi = max(maxi, dp[i - 1][j - 1] - A[j - 2]);
            dp[i][j] = max(dp[i][j - 1], maxi + A[j - 1]);
        }
    }
    return dp[k][n];
}