#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// DFS
bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void DFS(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    int xdir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int ydir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int pos = 8;
    for (int k = 0; k < pos; k++)
    {
        int ni = i + xdir[k];
        int nj = j + ydir[k];
        if (isSafe(ni, nj, n, m) && !vis[ni][nj] && grid[ni][nj] == '1')
            DFS(ni, nj, n, m, grid, vis);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                DFS(i, j, n, m, grid, vis);
                c++;
            }
        }
    }
    return c;
}

// Without space
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int islands = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                eraseIslands(grid, i, j, m, n);
            }
        }
    }
    return islands;
}
void eraseIslands(vector<vector<char>> &grid, int i, int j, int m, int n)
{
    if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    eraseIslands(grid, i - 1, j, m, n);
    eraseIslands(grid, i + 1, j, m, n);
    eraseIslands(grid, i, j - 1, m, n);
    eraseIslands(grid, i, j + 1, m, n);
}

// BFS
bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and grid[i][j] == '1')
            {
                c++;
                vis[i][j] = true;

                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> temp = q.front();
                    int x = temp.first;
                    int y = temp.second;
                    q.pop();

                    vector<int> dx{-1, 0, 1, 0, 1, -1, -1, 1};
                    vector<int> dy{0, -1, 0, 1, 1, 1, -1, -1};
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (isSafe(nx, ny, n, m) &&
                            !vis[nx][ny] &&
                            grid[nx][ny] == '1')
                        {
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    return c;
}