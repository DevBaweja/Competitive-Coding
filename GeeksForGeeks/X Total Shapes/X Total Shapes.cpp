#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int curx, int cury, int n, int m, vector<vector<char>> &grid)
{
    grid[curx][cury] = 'O';
    int size = 4;
    vector<int> dirx = {0, 1, 0, -1};
    vector<int> diry = {1, 0, -1, 0};
    for (int k = 0; k < size; k++)
    {
        int nextx = curx + dirx[k];
        int nexty = cury + diry[k];
        if (isSafe(nextx, nexty, n, m) && grid[nextx][nexty] == 'X')
            dfs(nextx, nexty, n, m, grid);
    }
}

int xShape(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X')
            {
                count++;
                dfs(i, j, n, m, grid);
            }
        }
    }
    return count;
}