#include <bits/stdc++.h>
using namespace std;

double waterOverflow(int k, int r, int c)
{
    vector<vector<double>> dp(k, vector<double>(k, 0.0));
    dp[0][0] = k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (dp[i][j] > 1.0)
            {
                double val = dp[i][j] - 1.0;
                dp[i][j] = 1.0;
                dp[i + 1][j] += val / 2.0;
                dp[i + 1][j + 1] = val / 2.0;
            }
        }
    }
    return dp[r - 1][c - 1];
}