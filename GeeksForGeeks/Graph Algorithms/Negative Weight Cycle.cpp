#include <bits/stdc++.h>
using namespace std;

int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<int> d(n, INT_MAX);
    d[0] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (vector<int> el : edges)
        {
            int u = el[0], v = el[1], w = el[2];
            if (d[u] != INT_MAX && d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }
    for (vector<int> el : edges)
    {
        int u = el[0], v = el[1], w = el[2];
        if (d[u] != INT_MAX && d[u] + w < d[v])
            return 1;
    }
    return 0;
}