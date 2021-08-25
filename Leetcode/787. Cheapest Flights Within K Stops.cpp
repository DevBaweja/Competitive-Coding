#include <bits/stdc++.h>
using namespace std;

// Priority Queue with Pruning
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> graph(n);
    for (vector<int> edge : flights)
        graph[edge[0]].push_back({edge[1], edge[2]});

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push(make_pair(0, make_pair(src, 0)));
    vector<int> dist(n + 1, INT_MAX);
    while (!pq.empty())
    {
        pair<int, pair<int, int>> temp = pq.top();
        int c = temp.first;
        int u = temp.second.first;
        int s = temp.second.second;
        pq.pop();
        if (u == dst)
            return c;
        if (dist[u] < s)
            continue;
        dist[u] = s;
        if (s > k)
            continue;
        for (pair<int, int> temp : graph[u])
        {
            int v = temp.first;
            int w = temp.second;
            pq.push(make_pair(c + w, make_pair(v, s + 1)));
        }
    }

    return -1;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<vector<int>>> graph(n);
    for (vector<int> el : flights)
        graph[el[0]].push_back({el[1], el[2]});

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<int> dist(n, INT_MAX);
    pq.push({0, src, 0});

    while (!pq.empty())
    {
        vector<int> el = pq.top();
        pq.pop();
        int c = el[0], u = el[1], s = el[2];
        if (u == dst)
            return c;
        if (dist[u] < s)
            continue;
        dist[u] = s;
        if (s > k)
            continue;
        for (vector<int> t : graph[u])
        {
            int v = t[0];
            int nc = t[1];
            pq.push({c + nc, v, s + 1});
        }
    }
    return -1;
}