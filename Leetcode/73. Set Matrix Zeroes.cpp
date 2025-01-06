#include <bits/stdc++.h>
using namespace std;

// Maintain every x and y
// Space - O(n*m)
void setZeroes(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!grid[i][j])
                v.push_back({i, j});

    for (pair<int, int> p : v)
    {
        int x = p.first;
        int y = p.second;

        int tx, ty;
        tx = x;
        ty = y;
        while (tx >= 0)
            grid[tx--][ty] = 0;
        tx = x;
        ty = y;
        while (tx < n)
            grid[tx++][ty] = 0;
        tx = x;
        ty = y;
        while (ty >= 0)
            grid[tx][ty--] = 0;
        tx = x;
        ty = y;
        while (ty < m)
            grid[tx][ty++] = 0;
    }
}

// Maintain every row and col
// Space - O(n+m)
void setZeroes(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    unordered_set<int> sx, sy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!grid[i][j])
            {
                sx.insert(i);
                sy.insert(j);
            }

    for (int x : sx)
        for (int y = 0; y < m; y++)
            grid[x][y] = 0;
    for (int y : sy)
        for (int x = 0; x < n; x++)
            grid[x][y] = 0;
}

// Using first row and col
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[n-1].size();

    vector<int> row(n, -1);
    vector<int> col(m, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(row[i] == 0) {
            for(int j=0; j<m; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for(int j=0; j<m; j++) {
        if(col[j] == 0) {
            for(int i=0; i<n; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    
}

// Using first row and col
// Space - O(1)
void setZeroes(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    bool row = false, col = false;
    for (int i = 0; i < n; i++)
        row |= !grid[i][0];
    for (int j = 0; j < m; j++)
        col |= !grid[0][j];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (!grid[i][j])
            {
                grid[i][0] = 0;
                grid[0][j] = 0;
            }

    for (int i = 1; i < n; i++)
    {
        if (!grid[i][0])
        {
            for (int j = 1; j < m; j++)
                grid[i][j] = 0;
        }
    }
    for (int j = 1; j < m; j++)
    {
        if (!grid[0][j])
        {
            for (int i = 1; i < n; i++)
                grid[i][j] = 0;
        }
    }

    if (row)
    {
        for (int i = 0; i < n; i++)
            grid[i][0] = 0;
    }
    if (col)
    {
        for (int j = 0; j < m; j++)
            grid[0][j] = 0;
    }
}

// Using first row and col
// Space - O(1)
void setZeroes(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    bool row = false, col = false;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!grid[i][j])
            {
                if (i == 0)
                    col = true;
                if (j == 0)
                    row = true;
                grid[i][0] = 0;
                grid[0][j] = 0;
            }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (!grid[i][0] || !grid[0][j])
                grid[i][j] = 0;

    if (row)
    {
        for (int i = 0; i < n; i++)
            grid[i][0] = 0;
    }
    if (col)
    {
        for (int j = 0; j < m; j++)
            grid[0][j] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[n-1].size();

    bool fr = false, fc = false;
    for(int i=0; i<n; i++)
        fc |= !matrix[i][0];
    for(int j=0; j<m; j++)
        fr |= !matrix[0][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if(fr){
        for(int j=0; j<m; j++)
            matrix[0][j] = 0;
    }
    if(fc){
        for(int i=0; i<n; i++)
            matrix[i][0] = 0;
    }

}