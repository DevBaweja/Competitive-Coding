#include <bits/stdc++.h>
using namespace std;

// DP
int minFallingPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tl = (j != 0) ? grid[i - 1][j - 1] : INT_MAX;
            int tr = (j != m - 1) ? grid[i - 1][j + 1] : INT_MAX;
            int t = grid[i - 1][j];
            grid[i][j] += min({tl, t, tr});
        }
    }

    return *min_element(grid[n - 1].begin(), grid[n - 1].end());
}

// DFS
int minFallingPathSumUtil(vector<vector<int>> &matrix, int x, int y, int n, int m, map<pair<int, int>, int> &dp)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return INT_MAX;

    if (dp.find({x, y}) != dp.end())
        return dp[{x, y}];

    if (x == n - 1)
        return matrix[x][y];

    int l = minFallingPathSumUtil(matrix, x + 1, y - 1, n, m, dp);
    int d = minFallingPathSumUtil(matrix, x + 1, y, n, m, dp);
    int r = minFallingPathSumUtil(matrix, x + 1, y + 1, n, m, dp);
    return dp[{x, y}] = min(l, min(r, d)) + matrix[x][y];
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[n - 1].size();
    int ans = INT_MAX;
    map<pair<int, int>, int> dp;

    for (int j = 0; j < m; j++)
        ans = min(ans, minFallingPathSumUtil(matrix, 0, j, n, m, dp));
    return ans;
}