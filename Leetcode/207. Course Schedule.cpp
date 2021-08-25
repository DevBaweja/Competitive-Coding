#include <bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n);
    vector<int> inDeg(n, 0);
    for (vector<int> el : edges)
    {
        int u = el[0], v = el[1];
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

    for (int d : inDeg)
        if (d)
            return false;
    return true;
}