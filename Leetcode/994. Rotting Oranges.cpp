#include <bits/stdc++.h>
using namespace std;

// BFS
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 2)
                q.push({{i, j}, 0});

    int res = 0;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int curx = p.first.first;
            int cury = p.first.second;
            int time = p.second;

            res = max(res, time);

            vector<int> dx{-1, 0, 1, 0};
            vector<int> dy{0, 1, 0, -1};
            int size = 4;
            for (int k = 0; k < size; k++)
            {
                int nextx = curx + dx[k];
                int nexty = cury + dy[k];

                if (isSafe(nextx, nexty, n, m) && grid[nextx][nexty] == 1)
                {
                    q.push({{nextx, nexty}, time + 1});
                    grid[nextx][nexty] = 2;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                return -1;
    return res;
}

// BFS
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 2)
                q.push({{i, j}, 0});
    int res = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int curx = p.first.first;
            int cury = p.first.second;
            int time = p.second;
            res = time;
            vector<int> dirx{0, 1, 0, -1};
            vector<int> diry{1, 0, -1, 0};
            int size = 4;
            for (int k = 0; k < size; k++)
            {
                int nextx = curx + dirx[k];
                int nexty = cury + diry[k];
                if (isSafe(nextx, nexty, n, m) && grid[nextx][nexty] == 1)
                {
                    q.push({{nextx, nexty}, time + 1});
                    grid[nextx][nexty] = 2;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                return -1;
    return res;
}

// BFS
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();
    queue<pair<int, int>> q;
    int time = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 2)
                q.push({i, j});

    vector<int> dirx{-1, 0, 1, 0};
    vector<int> diry{0, 1, 0, -1};
    int maxi = 4;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> t = q.front();
            int cx = t.first, cy = t.second;
            q.pop();
            for (int k = 0; k < maxi; k++)
            {
                int nx = cx + dirx[k];
                int ny = cy + diry[k];
                if (isSafe(nx, ny, n, m) && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        time++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                return -1;
    if (time == -1)
        time++;
    return time;
}