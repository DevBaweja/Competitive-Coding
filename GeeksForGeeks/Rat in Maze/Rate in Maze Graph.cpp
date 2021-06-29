#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

void DFS(int x, int y, string s, int n, vector<vector<int>> &m,
         vector<vector<bool>> &vis, vector<string> &res)
{
    if (!isSafe(x, y, n))
        return;
    if (!m[x][y] || vis[x][y])
        return;

    if (x == n - 1 && y == n - 1)
    {
        res.push_back(s);
        return;
    }
    vis[x][y] = true;
    vector<int> xdir{0, 1, 0, -1};
    vector<int> ydir{1, 0, -1, 0};
    ;
    vector<string> str{"R", "D", "L", "U"};
    int pos = 4;
    for (int i = 0; i < pos; i++)
    {
        int nx = x + xdir[i];
        int ny = y + ydir[i];
        DFS(nx, ny, s + str[i], n, m, vis, res);
    }
    vis[x][y] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    if (!m[0][0] || !m[n - 1][n - 1])
        return {};

    string s = "";
    vector<string> res;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    DFS(0, 0, s, n, m, vis, res);
    sort(res.begin(), res.end());
    return res;
}