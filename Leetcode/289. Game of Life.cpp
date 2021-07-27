#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < m && y < n);
}

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> newBoard(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int x = i - 1; x <= i + 1; x++)
                for (int y = j - 1; y <= j + 1; y++)
                    if (isSafe(x, y, n, m))
                        if (x != i || y != j)
                            count += board[x][y];
            if (count == 2)
                newBoard[i][j] = board[i][j];
            if (count == 3)
                newBoard[i][j] = 1;
            if (count < 2 || count > 3)
                newBoard[i][j] = 0;
        }

    board = newBoard;
}