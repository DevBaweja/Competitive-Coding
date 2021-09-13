#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &grid, int n, int m)
{

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    return dp[n - 1][m - 1];
}

int minCost(vector<vector<int>> &grid, int n, int m)
{
    for (int j = 1; j < m; j++)
        grid[0][j] += grid[0][j - 1];
    for (int i = 1; i < n; i++)
        grid[i][0] += grid[i - 1][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    return grid[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << minCost(grid, n, m);
}