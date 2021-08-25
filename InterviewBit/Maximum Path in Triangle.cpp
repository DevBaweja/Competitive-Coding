#include <bits/stdc++.h>
using namespace std;

// Top Down
int solve(vector<vector<int>> &A)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int l = j != 0 ? A[i - 1][j - 1] : 0;
            int r = A[i - 1][j];
            A[i][j] += max(l, r);
        }
    }
    return *max_element(A[n - 1].begin(), A[n - 1].end());
}

// Bottom Up
int solve(vector<vector<int>> &A)
{
    int n = A.size();
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            A[i][j] += max(A[i + 1][j], A[i + 1][j + 1]);
        }
    }
    return A[0][0];
}