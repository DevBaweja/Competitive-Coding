#include <bits/stdc++.h>
using namespace std;

// DP
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (i == m - 1 && j == n - 1)
                dp[i][j] = 1;
            else if (i == m - 1)
                dp[i][j] = dp[i][j + 1];
            else if (j == n - 1)
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    return dp[0][0];
}

// DP
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}

// DP Space
int uniquePaths(int m, int n)
{
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            cur[j] += cur[j - 1];
    return cur[n - 1];
}
