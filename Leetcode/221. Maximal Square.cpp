#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == '1')
                dp[i][j] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (dp[i][j] && dp[i - 1][j] && dp[i][j - 1] && dp[i - 1][j - 1])
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, dp[i][j] * dp[i][j]);

    return res;
}