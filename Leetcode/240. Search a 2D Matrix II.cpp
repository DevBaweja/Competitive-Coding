#include <bits/stdc++.h>
using namespace std;

// Top Right Search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[n - 1].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

// Divide and Conquer
bool searchMatrixUtil(vector<vector<int>> &matrix, int n, int m, int target, int hl, int hr, int vl, int vr)
{
    if ((hl > hr) || (vl > vr))
        return false;
    int midh = (hl + hr) / 2;
    int midv = (vl + vr) / 2;

    int cand = matrix[midh][midv];
    if (cand == target)
        return true;
    if (cand > target)
        return searchMatrixUtil(matrix, n, m, target, hl, midh - 1, vl, vr) || searchMatrixUtil(matrix, n, m, target, hl, hr, vl, midv - 1);
    return searchMatrixUtil(matrix, n, m, target, midh + 1, hr, vl, vr) || searchMatrixUtil(matrix, n, m, target, hl, hr, midv + 1, vr);
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[n - 1].size();
    return searchMatrixUtil(matrix, n, m, target, 0, n - 1, 0, m - 1);
}