#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
{
    vector<int> d(V, 1e8);
    d[S] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        bool flag = 0;
        for (vector<int> el : adj)
        {
            int u = el[0], v = el[1], w = el[2];
            if (d[u] != 1e8 && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    return d;
}