#include <bits/stdc++.h>
using namespace std;

// Count Component difference
void dfs(int cur, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[cur] = true;
    for (int el : graph[cur])
    {
        if (!vis[el])
            dfs(el, graph, vis);
    }
}

int count(vector<vector<int>> &graph, int n)
{
    vector<bool> vis(n, false);
    int c = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            dfs(i, graph, vis);
            c++;
        }
    return c;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> graph(n);
    for (vector<int> edge : connections)
    {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> res;
    for (vector<int> edge : connections)
    {
        int u = edge[0], v = edge[1];
        auto a = find(graph[u].begin(), graph[u].end(), v);
        graph[u].erase(a);
        auto b = find(graph[v].begin(), graph[v].end(), u);
        graph[v].erase(b);
        if (count(graph, n) != 1)
            res.push_back(edge);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return res;
}