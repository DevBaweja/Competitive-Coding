#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, int dest, vector<int> &vis, vector<vector<int>> &graph, int &res)
{
    if (cur == dest)
    {
        res++;
        return;
    }
    vis[cur] = 1;
    for (int next : graph[cur])
        if (!vis[next])
            dfs(next, dest, vis, graph, res);

    vis[cur] = 0;
}

int possible_paths(vector<vector<int>> edges, int n, int s, int d)
{
    vector<vector<int>> graph(n);
    for (vector<int> p : edges)
    {
        int u = p[0];
        int v = p[1];
        graph[u].push_back(v);
    }

    vector<int> vis(n, 0);
    int res = 0;
    dfs(s, d, vis, graph, res);
    return res;
}