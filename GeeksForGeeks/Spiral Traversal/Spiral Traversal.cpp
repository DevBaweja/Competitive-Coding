#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int r, int c, vector<vector<int>> &vis)
{
    return ((x >= 0 && y >= 0 && x < r && y < c) && (!vis[x][y]));
}

void traversal(vector<vector<int>> matrix, int curx, int cury, int dir, int r, int c, vector<int> &res, vector<vector<int>> &vis)
{
    vis[curx][cury] = 1;
    res.push_back(matrix[curx][cury]);

    if (dir == 0)
    {
        if (isSafe(curx, cury + 1, r, c, vis))
            traversal(matrix, curx, cury + 1, dir, r, c, res, vis);
        else if (isSafe(curx + 1, cury, r, c, vis))
            traversal(matrix, curx + 1, cury, (dir + 1) % 4, r, c, res, vis);
    }
    else if (dir == 1)
    {
        if (isSafe(curx + 1, cury, r, c, vis))
            traversal(matrix, curx + 1, cury, dir, r, c, res, vis);
        else if (isSafe(curx, cury - 1, r, c, vis))
            traversal(matrix, curx, cury - 1, (dir + 1) % 4, r, c, res, vis);
    }
    else if (dir == 2)
    {
        if (isSafe(curx, cury - 1, r, c, vis))
            traversal(matrix, curx, cury - 1, dir, r, c, res, vis);
        else if (isSafe(curx - 1, cury, r, c, vis))
            traversal(matrix, curx - 1, cury, (dir + 1) % 4, r, c, res, vis);
    }
    else if (dir == 3)
    {
        if (isSafe(curx - 1, cury, r, c, vis))
            traversal(matrix, curx - 1, cury, dir, r, c, res, vis);
        else if (isSafe(curx, cury + 1, r, c, vis))
            traversal(matrix, curx, cury + 1, (dir + 1) % 4, r, c, res, vis);
    }
}

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> res;
    vector<vector<int>> vis(r, vector<int>(c, 0));
    traversal(matrix, 0, 0, 0, r, c, res, vis);
    return res;
}

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    int row = 0, col = 0;
    vector<int> res;

    while (row < r && col < c)
    {
        for (int i = col; i < c; i++)
            res.push_back(matrix[row][i]);
        row++;

        for (int i = row; i < r; i++)
            res.push_back(matrix[i][c - 1]);
        c--;

        if (row < r)
        {
            for (int i = c - 1; i >= col; i--)
                res.push_back(matrix[r - 1][i]);
            r--;
        }
        if (col < c)
        {
            for (int i = r - 1; i >= row; i--)
                res.push_back(matrix[i][col]);
            col++;
        }
    }
    return res;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];

    vector<int> res = spirallyTraverse(matrix, r, c);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}