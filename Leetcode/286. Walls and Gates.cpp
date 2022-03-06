#include <bits/stdc++.h>
using namespace std;

// BFS
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void wallsAndGates(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!grid[i][j])
                q.push({i, j});

    int dist = 1;
    vector<int> dirx{1, 0, -1, 0};
    vector<int> diry{0, 1, 0, -1};
    int dir = 4;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            int cx = p.first, cy = p.second;
            q.pop();
            for (int k = 0; k < dir; k++)
            {
                int nx = cx + dirx[k];
                int ny = cy + diry[k];
                if (isSafe(nx, ny, n, m) && grid[nx][ny] == INT_MAX)
                {
                    grid[nx][ny] = dist;
                    q.push({nx, ny});
                }
            }
        }
        dist++;
    }
}