#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<pair<int, int>>> &graph, int v)
{
    vector<int> inDegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (pair<int, int> t : graph[i])
        {
            int j = t.first;
            inDegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
        if (!inDegree[i])
            q.push(i);

    vector<int> res;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (pair<int, int> t : graph[u])
        {
            int v = t.first;
            inDegree[v]--;
            if (!inDegree[v])
                q.push(v);
        }
    }
    return res;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int src;
    cin >> src;
    vector<vector<pair<int, int>>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> res = topologicalSort(graph, v);
    vector<int> dist(v, INT_MIN);
    dist[src] = 0;
    for (int i = v - 1; i >= 0; i--)
    {
        if (dist[res[i]] != INT_MIN)
        {
            for (pair<int, int> t : graph[res[i]])
            {
                int u = dist[res[i]];
                int v = dist[t.first];
                int w = t.second;
                if (u + w > v)
                    dist[t.first] = u + w;
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (i != src && dist[i] != INT_MIN)
            cout << src << "-->" << i << "=" << dist[i] << endl;
    }
    return 0;
}

// 6 10
// 1
// 0 1 5
// 0 2 3
// 1 3 6
// 1 2 2
// 2 4 4
// 2 5 2
// 2 3 7
// 3 5 1
// 3 4 -1
// 4 5 -2

// 6 6
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1

// 6 7
// 1
// 0 1 5
// 1 5 5
// 5 3 2
// 3 2 20
// 4 2 10
// 5 2 50
// 1 4 2