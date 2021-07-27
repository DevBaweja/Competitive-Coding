#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> dp(numRows);
    dp[0].push_back(1);
    for (int i = 1; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j)
                dp[i].push_back(dp[i - 1][j]);
            else if (i == j)
                dp[i].push_back(dp[i - 1][j - 1]);
            else
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
        }
    }
    return dp;
}