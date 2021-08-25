#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, vector<pair<int, int>> &pre)
{
    vector<vector<int>> graph(n);
    vector<int> inDeg(n, 0);
    for (pair<int, int> p : pre)
    {
        int u = p.first, v = p.second;
        graph[u].push_back(v);
        inDeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!inDeg[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            inDeg[v]--;
            if (!inDeg[v])
                q.push(v);
        }
    }
    for (int i = 0; i < n; i++)
        if (inDeg[i])
            return false;
    return true;
}