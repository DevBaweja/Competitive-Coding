#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool isSafe(int x, int y, int n, int m, vector<vector<int>> &grid)
{
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y]);
}

void dfs(int x, int y, int n, int m, vector<vector<int>> &grid, vector<int> &dx, vector<int> &dy, vector<pair<int, int>> &v)
{
    if (!isSafe(x, y, n, m, grid))
        return;
    v.push_back({x, y});
    grid[x][y] = 0;

    int size = 4;
    for (int k = 0; k < size; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        dfs(nx, ny, n, m, grid, dx, dy, v);
    }
}
int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    vector<pair<int, int>> v1, v2;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
            {
                if (!v1.size())
                    dfs(i, j, n, m, grid, dx, dy, v1);
                if (!v2.size())
                    dfs(i, j, n, m, grid, dx, dy, v2);
            }
        }
    }
    int res = INT_MAX;
    for (pair<int, int> p1 : v1)
        for (pair<int, int> p2 : v2)
            res = min(res, abs(p1.first - p2.first) + abs(p1.second - p2.second) - 1);

    return res;
}

// TODO

// Expansion
// Expansion with Find Union