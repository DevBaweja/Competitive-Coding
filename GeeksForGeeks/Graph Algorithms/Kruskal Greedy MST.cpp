#include <bits/stdc++.h>
using namespace std;

// Kruskal MST
int Find(vector<int> parent, int i)
{
    if (parent[i] != i)
        parent[i] = Find(parent, parent[i]);
    return parent[i];
}

void Union(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xset = Find(parent, x);
    int yset = Find(parent, y);

    if (rank[xset] < rank[yset])
        parent[xset] = yset;
    else if (rank[xset] > rank[yset])
        parent[yset] = xset;
    else
    {
        parent[xset] = yset;
        rank[yset]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{

    set<vector<int>> edges;
    for (int x = 0; x < V; x++)
    {
        for (vector<int> temp : adj[x])
        {
            int y = temp[0];
            int w = temp[1];
            edges.insert({w, min(x, y), max(x, y)});
        }
    }

    vector<int> parent(V, -1);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<int> rank(V, 0);
    int cost = 0;
    for (vector<int> edge : edges)
    {
        int x = edge[1];
        int y = edge[2];
        int xset = Find(parent, x);
        int yset = Find(parent, y);
        if (xset != yset)
        {
            cost += edge[0];
            Union(parent, rank, xset, yset);
        }
    }
    return cost;
}