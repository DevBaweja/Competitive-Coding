#include <bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> grid)
{
    if (n == 1 && m == 1)
        return grid[0][0];
    if (n == 1)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += grid[0][j];
        return sum;
    }
    if (m == 1)
    {
        int maxi = 0;
        for (int i = 0; i < n; i++)
            maxi = max(maxi, grid[i][0]);
        return maxi;
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int tval = i != 0 ? grid[i - 1][j - 1] : 0;
            int bval = i != n - 1 ? grid[i + 1][j - 1] : 0;
            int lval = grid[i][j - 1];
            int mval = max({tval, lval, bval});
            grid[i][j] += mval;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, grid[i][m - 1]);
    return res;
}