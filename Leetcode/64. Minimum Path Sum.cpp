#include <bits/stdc++.h>
using namespace std;

// DP
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                dp[i][j] = grid[i][j];
            else if (i == m - 1)
                dp[i][j] = dp[i][j + 1] + grid[i][j];
            else if (j == n - 1)
                dp[i][j] = dp[i + 1][j] + grid[i][j];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
    }
    return dp[0][0];
}

// DP Inplace
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                ;
            else if (i == m - 1)
                grid[i][j] += grid[i][j + 1];
            else if (j == n - 1)
                grid[i][j] += grid[i + 1][j];
            else
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
        }
    }
    return grid[0][0];
}

// Map or Matrix
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j++)
        dp[0][j] += dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    map<pair<int, int>, pair<int, int>> mp;
    // vector<vector<pair<int, int>>> mp(n, vector<pair<int, int>>(m));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int val = min(dp[i - 1][j], dp[i][j - 1]);
            if (val == dp[i - 1][j])
                mp[{i, j}] = {i - 1, j};
            else if (val == dp[i][j - 1])
                mp[{i, j}] = {i, j - 1};
            dp[i][j] = val + grid[i][j];
        }
    }

    vector<pair<int, int>> v;

    int i = n - 1, j = m - 1;
    v.push_back({i, j});
    while (i != 0 && j != 0)
    {
        pair<int, int> p = mp[{i, j}];
        i = p.first;
        j = p.second;
        v.push_back({i, j});
    }
    if (i)
        while (i--)
            v.push_back({i, j});
    if (j)
        while (j--)
            v.push_back({i, j});
    reverse(v.begin(), v.end());
    for (pair<int, int> p : v)
        cout << "(" << p.first << "," << p.second << ")" << endl;
    return dp[n - 1][m - 1];
}

// BFS
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j++)
        dp[0][j] += dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int curx = p.first;
            int cury = p.second;
            cout << curx << " " << cury << endl;
            int tval = INT_MAX;
            int lval = INT_MAX;
            if (curx)
                tval = dp[curx - 1][cury];

            if (cury)
                lval = dp[curx][cury - 1];

            int fval = min(tval, lval);
            if (fval != INT_MAX)
            {
                if (fval == tval)
                    q.push({curx - 1, cury});
                if (fval == lval)
                    q.push({curx, cury - 1});
            }
        }
    }

    return dp[n - 1][m - 1];
}