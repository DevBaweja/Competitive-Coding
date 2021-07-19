#include <bits/stdc++.h>
using namespace std;

// DFS
bool dfs(int u, int parent, int col, vector<int> &color, vector<int> adj[])
{
    if (color[u] != -1 && color[u] != col)
        return false;
    color[u] = col;
    vector<int> list = adj[u];
    bool res = true;
    for (int v : list)
    {
        if (color[v] == -1)
            res &= dfs(v, u, 3 - col, color, adj);
        else if ((v != parent && color[v] == color[u]) || u == v)
        {
            // is not parent and of same color
            // contain self loop
            return false;
        }
        if (!res)
            return false;
    }
    return true;
}

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(0, -1, 1, color, adj))
                return false;
        }
    }
    return true;
}

// BFS
bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int k : adj[u])
                {
                    if (color[k] == color[u])
                        return false;
                    if (color[k] == -1)
                    {
                        color[k] = 3 - color[u];
                        q.push(k);
                    }
                }
            }
        }
    }
    return true;
}