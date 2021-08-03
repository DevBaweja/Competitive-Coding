#include <bits/stdc++.h>
using namespace std;

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (mat[i][j] && mat[i - 1][j] && mat[i][j - 1] && mat[i - 1][j - 1])
                mat[i][j] = 1 + min({mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]});

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, mat[i][j]);

    return res;
}