#include <bits/stdc++.h>
using namespace std;

// Time - n2
// Space - n
int celebrity(vector<vector<int>> &M, int n)
{
    vector<int> in(n, 0);
    vector<int> out(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (M[i][j])
            {
                out[i]++;
                in[j]++;
            }

    for (int k = 0; k < n; k++)
        if (in[k] == n - 1 && out[k] == 0)
            return k;
    return -1;
}

// Time - n
// Space - 1
int celebrity(vector<vector<int>> &M, int n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
        if (M[c][i])
            c = i;

    for (int i = 0; i < n; i++)
        if (i != c && (M[c][i] || !M[i][c]))
            return -1;

    return c;
}