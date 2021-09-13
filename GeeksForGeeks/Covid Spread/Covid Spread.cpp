#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int helpaterp(vector<vector<int>> grid)
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
            int t = p.second;
            res = t;
            int size = 4;
            vector<int> dirx{0, 1, 0, -1};
            vector<int> diry{1, 0, -1, 0};

            for (int k = 0; k < size; k++)
            {
                int nextx = curx + dirx[k];
                int nexty = cury + diry[k];
                if (isSafe(nextx, nexty, n, m) && grid[nextx][nexty] == 1)
                {
                    q.push({{nextx, nexty}, t + 1});
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