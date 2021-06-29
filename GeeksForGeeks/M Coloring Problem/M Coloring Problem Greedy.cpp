#include <bits/stdc++.h>
using namespace std;

// Greedy
bool graphColoring(bool graph[101][101], int m, int v)
{
    vector<vector<int>> g(v);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (graph[i][j])
                g[i].push_back(j);

    int cn = 0;
    vector<int> colors(v, -1);
    for (int i = 0; i < v; i++)
    {
        vector<bool> available(v, true);
        for (int j : graph[i])
        {
            if (colors[j] != -1)
                available[colors[j]] = false;
        }

        int cr;
        for (cr = 0; cr < v; cr++)
        {
            if (available[cr])
                break;
        }

        colors[i] = cr;
        cn = max(cn, cr);
    }
    return cn < m;
}