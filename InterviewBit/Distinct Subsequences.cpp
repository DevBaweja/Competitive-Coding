#include <bits/stdc++.h>
using namespace std;

int numDistinct(string A, string B)
{
    int n = B.size(), m = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += dp[i][j - 1];
            if (B[i - 1] == A[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
