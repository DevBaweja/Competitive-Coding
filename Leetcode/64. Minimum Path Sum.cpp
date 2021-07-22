#include <bits/stdc++.h>
using namespace std;

// DP
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                dp[i][j] = grid[i][j];
            else if (i == m - 1)
                dp[i][j] = dp[i][j + 1] + grid[i][j];
            else if (j == n - 1)
                dp[i][j] = dp[i + 1][j] + grid[i][j];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
    }
    return dp[0][0];
}

// DP Inplace
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                ;
            else if (i == m - 1)
                grid[i][j] += grid[i][j + 1];
            else if (j == n - 1)
                grid[i][j] += grid[i + 1][j];
            else
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
        }
    }
    return grid[0][0];
}