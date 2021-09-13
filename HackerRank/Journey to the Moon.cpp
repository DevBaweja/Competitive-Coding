#include <bits/stdc++.h>
using namespace std;

long long comb(int n)
{
    if (n == 0)
        return 0;
    return 1ll * n * (n - 1) / 2;
}

void dfs(int cur, vector<vector<int>> &graph, vector<int> &vis, int &count)
{
    vis[cur] = 1;
    count++;
    for (int next : graph[cur])
        if (!vis[next])
            dfs(next, graph, vis, count);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; i++)
        cin >> edges[i].first >> edges[i].second;

    vector<vector<int>> graph(v);
    for (pair<int, int> el : edges)
    {
        graph[el.first].push_back(el.second);
        graph[el.second].push_back(el.first);
    }

    vector<int> vis(v, 0);
    long long res = comb(v);

    for (int i = 0; i < v; i++)
    {
        int count = 0;
        if (!vis[i])
            dfs(i, graph, vis, count);
        res -= comb(count);
    }
    cout << res;
}
