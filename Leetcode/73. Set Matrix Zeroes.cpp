#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!grid[i][j])
                v.push_back({i, j});

    for (pair<int, int> p : v)
    {
        int x = p.first;
        int y = p.second;

        int tx, ty;
        tx = x;
        ty = y;
        while (tx >= 0)
            grid[tx--][ty] = 0;
        tx = x;
        ty = y;
        while (tx < n)
            grid[tx++][ty] = 0;
        tx = x;
        ty = y;
        while (ty >= 0)
            grid[tx][ty--] = 0;
        tx = x;
        ty = y;
        while (ty < m)
            grid[tx][ty++] = 0;
    }
}