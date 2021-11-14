#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, int n, int m, vector<vector<int>> &grid, int &count)
{
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0)
        return;
    grid[x][y] = 0;
    count++;
    dfs(x + 1, y, n, m, grid, count);
    dfs(x, y + 1, n, m, grid, count);
    dfs(x - 1, y, n, m, grid, count);
    dfs(x, y - 1, n, m, grid, count);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int count = 0;
            dfs(i, j, n, m, grid, count);
            maxi = max(maxi, count);
        }
    }
    return maxi;
}