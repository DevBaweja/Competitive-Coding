#include <bits/stdc++.h>
using namespace std;

// Backtracking
void DFS(int x, int y, int n, int m, vector<vector<bool>> &matrix,
         vector<vector<bool>> &vis, int &count)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (matrix[x][y] || vis[x][y])
        return;

    if (x == n - 1 && y == m - 1)
    {
        count++;
        return;
    }
    vis[x][y] = true;
    DFS(x + 1, y, n, m, matrix, vis, count);
    DFS(x, y + 1, n, m, matrix, vis, count);
    vis[x][y] = false;
}
int FindWays(int n, int m, vector<vector<int>> blocked_cells)
{
    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    for (vector<int> el : blocked_cells)
        matrix[el[0] - 1][el[1] - 1] = true;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int count = 0;
    DFS(0, 0, n, m, matrix, vis, count);
    return count;
}