#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int k, vector<vector<pair<int, int>>> &graph, vector<bool> &vis)
{
    vis[u] = true;
    if (k <= 0)
        return true;
    for (pair<int, int> p : graph[u])
    {
        int v = p.first;
        int w = p.second;
        if (!vis[v])
        {
            if (w >= k)
                return true;
            if (dfs(v, k - w, graph, vis))
                return true;
        }
    }
    vis[u] = false;
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a)
{
    vector<vector<pair<int, int>>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int u = a[3 * i];
        int v = a[3 * i + 1];
        int w = a[3 * i + 2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<bool> vis(V, false);
    return dfs(0, k, graph, vis);
}