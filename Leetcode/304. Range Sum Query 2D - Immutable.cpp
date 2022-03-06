#include <bits/stdc++.h>
using namespace std;

// Brute Force
class NumMatrix
{
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int r = row1; r <= row2; r++)
            for (int c = col1; c <= col2; c++)
                sum += matrix[r][c];
        return sum;
    }
};

// 1D Prefix Sum
class NumMatrix
{
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[n - 1].size();
        for (int r = 0; r < n; r++)
            for (int c = 1; c < m; c++)
                matrix[r][c] += matrix[r][c - 1];
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int r = row1; r <= row2; r++)
        {
            int left = !col1 ? 0 : matrix[r][col1 - 1];
            int right = matrix[r][col2];
            sum += right - left;
        }
        return sum;
    }
};

// 2D Prefix Sum and Inclusion Exclusion
class NumMatrix
{
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[n - 1].size();
        for (int r = 1; r < n; r++)
            matrix[r][0] += matrix[r - 1][0];
        for (int c = 1; c < m; c++)
            matrix[0][c] += matrix[0][c - 1];
        for (int r = 1; r < n; r++)
            for (int c = 1; c < m; c++)
                matrix[r][c] += matrix[r][c - 1] + matrix[r - 1][c] - matrix[r - 1][c - 1];
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int A = !row1 ? 0 : matrix[row1 - 1][col2];
        int B = !col1 ? 0 : matrix[row2][col1 - 1];
        int AB = (!row1 || !col1) ? 0 : matrix[row1 - 1][col1 - 1];
        return matrix[row2][col2] - A - B + AB;
    }
};
