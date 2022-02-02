#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[cur] = true;
    for (int next : graph[cur])
    {
        if (!vis[next])
            dfs(next, graph, vis);
    }
}

int makeConnected(int n, vector<vector<int>> &edges)
{
    int m = edges.size();
    if (m < n - 1)
        return -1;

    vector<vector<int>> graph(n);
    for (vector<int> edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> vis(n, false);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, graph, vis);
            res++;
        }
    }
    return res - 1;
}