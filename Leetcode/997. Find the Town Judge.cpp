#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> in(n, 0);
    vector<int> out(n, 0);
    for (vector<int> el : trust)
    {
        out[el[0] - 1]++;
        in[el[1] - 1]++;
    }
    for (int i = 0; i < n; i++)
        if (out[i] == 0 && in[i] == n - 1)
            return i + 1;
    return -1;
}

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (vector<int> el : trust)
        mat[el[0] - 1][el[1] - 1] = 1;

    int c = 0;
    for (int i = 1; i < n; i++)
        if (mat[c][i])
            c = i;

    for (int i = 0; i < n; i++)
        if (i != c && (mat[c][i] == 1 || mat[i][c] == 0))
            return -1;

    return c + 1;
}
