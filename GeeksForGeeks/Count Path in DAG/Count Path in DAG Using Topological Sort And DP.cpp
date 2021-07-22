#include <bits/stdc++.h>
using namespace std;

vector<int> topological(vector<vector<int>> graph, int n)
{
    vector<int> inDeg(n, 0);
    for (int i = 0; i < n; i++)
        for (int j : graph[i])
            inDeg[j]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!inDeg[i])
            q.push(i);
    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : graph[u])
        {
            inDeg[v]--;
            if (!inDeg[v])
                q.push(v);
        }
    }
    return topo;
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

    vector<int> topo = topological(graph, n);

    vector<int> dp(n, 0);
    dp[d] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int u = topo[i];
        for (int v : graph[u])
        {
            dp[u] += dp[v];
        }
    }
    return dp[s];
}