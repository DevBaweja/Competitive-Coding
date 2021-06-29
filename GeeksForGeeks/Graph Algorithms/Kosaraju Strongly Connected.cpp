#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<int> adj[], vector<bool> &vis, vector<int> &order)
{
    vis[cur] = true;
    for (int v : adj[cur])
        if (!vis[v])
            dfs(v, adj, vis, order);
    order.push_back(cur);
}

void revdfs(int cur, vector<int> revadj[], vector<bool> &revvis)
{
    revvis[cur] = true;
    for (int v : revadj[cur])
        if (!revvis[v])
            revdfs(v, revadj, revvis);
}

int kosaraju(int V, vector<int> adj[])
{

    vector<bool> vis(V, false);
    vector<int> order;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, order);
    }

    vector<int> revadj[V];
    for (int i = 0; i < V; i++)
        for (int j : adj[i])
            revadj[j].push_back(i);

    int count = 0;
    vector<bool> revvis(V, false);
    for (int i = V - 1; i >= 0; i--)
    {
        if (!revvis[order[i]])
        {
            revdfs(order[i], revadj, revvis);
            count++;
        }
    }
    return count;
}