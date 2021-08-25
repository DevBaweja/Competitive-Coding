#include <bits/stdc++.h>
using namespace std;

bool isBipartition(vector<vector<int>> &graph, int n, vector<int> &color, int src)
{
    queue<int> q;
    q.push(src);
    color[src] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
                return false;
        }
    }
    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<vector<int>> graph(n);
    for (vector<int> el : dislikes)
    {
        int u = el[0] - 1;
        int v = el[1] - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartition(graph, n, color, i))
                return false;
        }
    }
    return true;
}