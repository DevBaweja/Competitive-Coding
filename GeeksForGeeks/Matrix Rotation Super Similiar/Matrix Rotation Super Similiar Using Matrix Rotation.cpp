#include <bits/stdc++.h>
using namespace std;

int isSuperSimilar(int n, int m, vector<vector<int>> &mat, int x)
{
    if (x % m == 0)
        return true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] != mat[i][(j + m - x) % m])
                return false;
    return true;
}