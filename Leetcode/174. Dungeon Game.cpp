#include <bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    grid[n - 1][m - 1] = min(grid[n - 1][m - 1], 0);
    for (int j = m - 2; j >= 0; j--)
    {
        grid[n - 1][j] += grid[n - 1][j + 1];
        grid[n - 1][j] = min(grid[n - 1][j], 0);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        grid[i][m - 1] += grid[i + 1][m - 1];
        grid[i][m - 1] = min(grid[i][m - 1], 0);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            grid[i][j] += max(grid[i + 1][j], grid[i][j + 1]);
            grid[i][j] = min(grid[i][j], 0);
        }
    }
    return -grid[0][0] + 1;
}