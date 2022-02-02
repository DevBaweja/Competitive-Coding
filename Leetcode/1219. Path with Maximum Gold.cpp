#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
    return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && grid[x][y]);
}

int getMaximumGoldUtil(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
    if (!isSafe(x, y, n, m, grid, vis))
        return 0;
    vector<int> dirx{1, 0, -1, 0};
    vector<int> diry{0, 1, 0, -1};
    int size = 4;
    vis[x][y] = true;
    int res = 0;
    for (int k = 0; k < size; k++)
    {
        int nx = x + dirx[k];
        int ny = y + diry[k];
        res = max(res, getMaximumGoldUtil(nx, ny, n, m, grid, vis));
    }
    vis[x][y] = false;
    return grid[x][y] + res;
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();
    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            int res = getMaximumGoldUtil(x, y, n, m, grid, vis);
            ans = max(ans, res);
        }
    }
    return ans;
}