#include <bits/stdc++.h>
using namespace std;

// DP
vector<int> findBall(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    vector<vector<int>> loc(m);
    for (int k = 0; k < m; k++)
        loc[k].push_back(k);

    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> nloc(m);
        for (int j = 0; j < m; j++)
        {
            if (j != 0 && grid[i][j - 1] == 1 && grid[i][j] == 1)
            {
                for (int el : loc[j - 1])
                    nloc[j].push_back(el);
            }
            if (j != m - 1 && grid[i][j + 1] == -1 && grid[i][j] == -1)
            {
                for (int el : loc[j + 1])
                    nloc[j].push_back(el);
            }
        }
        loc = nloc;
    }
    vector<int> res(m, -1);
    for (int k = 0; k < m; k++)
        for (int el : loc[k])
            res[el] = k;
    return res;
}

// DFS
vector<int> findBall(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    vector<int> res(m, -1);
    for (int j = 0; j < m; j++)
    {
        int prev = j;
        for (int i = 0; i < n; i++)
        {
            int next = prev + grid[i][prev];
            if (next < 0 || next >= m || grid[i][prev] != grid[i][next])
            {
                prev = -1;
                break;
            }
            prev = next;
        }
        res[j] = prev;
    }
    return res;
}

// TODO
// Upscaled Grid