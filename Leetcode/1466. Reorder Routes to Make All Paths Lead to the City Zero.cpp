#include <bits/stdc++.h>
using namespace std;

// Track direction
void dfs(int cur, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, int &count)
{
    vis[cur] = true;
    for (pair<int, int> p : graph[cur])
    {
        int next = p.first, dir = p.second;
        if (!vis[next])
        {
            count += p.second;
            dfs(next, graph, vis, count);
        }
    }
}

int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<pair<int, int>>> graph(n);
    for (vector<int> connection : connections)
    {
        int u = connection[0], v = connection[1];
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 0});
    }
    vector<bool> vis(n, false);
    int count = 0;
    dfs(0, graph, vis, count);
    return count;
}

// TODO Edge Deletion