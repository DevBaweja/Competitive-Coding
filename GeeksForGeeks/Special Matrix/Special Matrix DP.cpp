#include <bits/stdc++.h>
using namespace std;

// DP
int FindWays(int n, int m, vector<vector<int>> blocked_cells)
{
    int mod = 1e9 + 7;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (vector<int> el : blocked_cells)
        matrix[el[0] - 1][el[1] - 1] = -1;

    // seed
    int i;
    for (i = 0; i < n; i++)
        if (matrix[i][0] != -1)
            matrix[i][0] = 1;
        else
            break;
    while (i < n)
        matrix[i++][0] = -1;
    int j;
    for (j = 0; j < m; j++)
        if (matrix[0][j] != -1)
            matrix[0][j] = 1;
        else
            break;
    while (j < m)
        matrix[0][j++] = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == -1)
                continue;
            if (matrix[i - 1][j] == -1 && matrix[i][j - 1] == -1)
                matrix[i][j] = -1;
            else if (matrix[i - 1][j] == -1)
                matrix[i][j] = matrix[i][j - 1];
            else if (matrix[i][j - 1] == -1)
                matrix[i][j] = matrix[i - 1][j];
            else
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            matrix[i][j] %= mod;
        }
    }
    return matrix[n - 1][m - 1] > 0 ? matrix[n - 1][m - 1] : 0;
}