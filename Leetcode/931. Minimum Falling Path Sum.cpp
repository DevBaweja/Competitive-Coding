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