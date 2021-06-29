#include <bits/stdc++.h>
using namespace std;

int countPS(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        dp[i - 1][i] = 1;

    for (int g = 1; g <= n; g++)
    {
        for (int i = 1, j = g; j <= n; i++, j++)
        {
            if (str[i - 1] == str[j - 1])
                dp[i - 1][j] = dp[i][j] + dp[i - 1][j - 1] + 1;
            else
                dp[i - 1][j] = dp[i][j] + dp[i - 1][j - 1] - dp[i][j - 1];
        }
    }
    return dp[0][n];
}