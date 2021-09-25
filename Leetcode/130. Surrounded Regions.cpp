#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
// DFS
void fill(int curx, int cury, int n, int m, char from, char to, vector<vector<char>> &board)
{

    if (board[curx][cury] != from)
        return;
    board[curx][cury] = to;

    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, 1, 0, -1};
    int size = 4;
    for (int k = 0; k < size; k++)
    {
        int nextx = curx + dx[k];
        int nexty = cury + dy[k];
        if (isSafe(nextx, nexty, n, m))
            fill(nextx, nexty, n, m, from, to, board);
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    if (n <= 2 && m <= 2)
        return;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 'O')
                board[i][j] = 'Y';

    for (int j = 0; j < m - 1; j++)
        if (board[0][j] == 'Y')
            fill(0, j, n, m, 'Y', 'O', board);
    for (int i = 0; i < n - 1; i++)
        if (board[i][m - 1] == 'Y')
            fill(i, m - 1, n, m, 'Y', 'O', board);
    for (int j = m - 1; j >= 1; j--)
        if (board[n - 1][j] == 'Y')
            fill(n - 1, j, n, m, 'Y', 'O', board);
    for (int i = n - 1; i >= 1; i--)
        if (board[i][0] == 'Y')
            fill(i, 0, n, m, 'Y', 'O', board);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 'Y')
                board[i][j] = 'X';
}

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
void fill(int curx, int cury, vector<vector<char>> &board, int n, int m)
{
    if (board[curx][cury] != 'O')
        return;
    queue<pair<int, int>> q;
    q.push({curx, cury});
    board[curx][cury] = 'Y';
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int cx = p.first;
            int cy = p.second;
            vector<int> dx{0, 1, 0, -1};
            vector<int> dy{1, 0, -1, 0};
            int size = 4;
            for (int k = 0; k < size; k++)
            {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (isSafe(nx, ny, n, m) && board[nx][ny] == 'O')
                {
                    q.push({nx, ny});
                    board[nx][ny] = 'Y';
                }
            }
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();

    for (int j = 0; j < m; j++)
    {
        fill(0, j, board, n, m);
        fill(n - 1, j, board, n, m);
    }
    for (int i = 0; i < n; i++)
    {
        fill(i, 0, board, n, m);
        fill(i, m - 1, board, n, m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            if (board[i][j] == 'Y')
                board[i][j] = 'O';
        }
    }
}