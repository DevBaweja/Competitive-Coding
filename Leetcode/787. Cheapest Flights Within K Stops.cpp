#include <bits/stdc++.h>
using namespace std;

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