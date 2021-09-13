#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost, int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i <= n; i++)
    {
        if (i == n)
            dp[i] = min(dp[i - 1], dp[i - 2]);
        else
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return dp[n];
}