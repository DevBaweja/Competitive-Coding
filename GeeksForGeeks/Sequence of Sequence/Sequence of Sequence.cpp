#include <bits/stdc++.h>
using namespace std;

int numberSequence(int m, int n)
{
    if (n == 1)
        return m;
    int count = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; j++)
        dp[1][j] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            int sum = 0;
            for (int k = j / 2; k >= 1; k--)
                sum += dp[i - 1][k];
            dp[i][j] = sum;
            if (i == n)
                count += dp[i][j];
        }
    }
    return count;
}

int numberSequence(int m, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; j++)
        dp[1][j] = j;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j / 2] + dp[i][j - 1];
        }
    }
    return dp[n][m];
}