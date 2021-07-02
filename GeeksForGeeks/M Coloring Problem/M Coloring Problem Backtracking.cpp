#include <bits/stdc++.h>
using namespace std;

bool isSafe(bool graph[101][101], int v, vector<int> &color, int cur, int col)
{
    for (int i = 0; i < v; i++)
    {
        if (graph[cur][i] && color[i] == col)
            return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int v, vector<int> &color, int cur)
{
    if (cur == v)
        return true;
    for (int col = 1; col <= m; col++)
    {
        if (isSafe(graph, v, color, cur, col))
        {
            color[cur] = col;
            if (graphColoringUtil(graph, m, v, color, cur + 1))
                return true;
            color[cur] = -1;
        }
    }

    return false;
}

// Backtracking
bool graphColoring(bool graph[101][101], int m, int v)
{
    vector<int> color(v, -1);
    return graphColoringUtil(graph, m, v, color, 0);
}