#include <bits/stdc++.h>
using namespace std;

// DFS with backtracking
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool dfs(vector<vector<char>> &board, int i, int j, int n, int m, int index, string &word, vector<vector<bool>> &vis, vector<int> &dirx, vector<int> &diry)
{
    char cand = board[i][j];
    int len = word.size();
    if (index == len - 1 && word[index] == cand)
        return true;
    if (word[index] != cand)
        return false;
    vis[i][j] = true;
    int dir = 4;
    for (int k = 0; k < dir; k++)
    {
        int nx = i + dirx[k];
        int ny = j + diry[k];
        if (isSafe(nx, ny, n, m) && !vis[nx][ny])
        {
            if (dfs(board, nx, ny, n, m, index + 1, word, vis, dirx, diry))
            {
                vis[i][j] = false;
                return true;
            }
        }
    }
    return vis[i][j] = false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[n - 1].size();
    vector<int> dirx{1, 0, -1, 0};
    vector<int> diry{0, 1, 0, -1};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dfs(board, i, j, n, m, 0, word, vis, dirx, diry))
                return true;
    return false;
}