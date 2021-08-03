#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (n == 1 && m == 1)
        return matrix[0][0] == target;
    int l1 = 0, h1 = n - 1;
    int c = 0;
    while (l1 <= h1)
    {
        int m1 = l1 + (h1 - l1) / 2;
        if (matrix[m1][c] <= target)
            l1 = m1 + 1;
        else
            h1 = m1 - 1;
    }
    int r = h1;
    if (r < 0)
        return false;
    int l2 = 0, h2 = m - 1;
    while (l2 <= h2)
    {
        int m2 = l2 + (h2 - l2) / 2;
        if (matrix[r][m2] == target)
            return true;
        if (matrix[r][m2] < target)
            l2 = m2 + 1;
        else
            h2 = m2 - 1;
    }
    return false;
}