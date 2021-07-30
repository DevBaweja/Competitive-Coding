#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, int src, vector<vector<pair<int, int>>> &graph)
{
    vector<int> dist(v + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        for (pair<int, int> t : graph[u])
        {
            int v = t.first;
            int w = t.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v + 1);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back({y, 0});
        graph[v].push_back({x, 1});
    }

    vector<int> dist = dijkstra(v, 1, graph);
    if (dist[v] == INT_MAX)
        dist[v] = -1;
    cout << dist[v];
}