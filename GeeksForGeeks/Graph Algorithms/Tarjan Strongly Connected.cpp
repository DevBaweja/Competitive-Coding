#include <bits/stdc++.h>
using namespace std;

// low - earliest visited vertex
int dfs(int cur, vector<int> adj[], vector<int> &dis, vector<int> &low, int &t, vector<bool> &inStack)
{
    dis[cur] = t;
    low[cur] = t;
    inStack[cur] = true;
    t++;
    for (int el : adj[cur])
    {
        if (dis[el] == -1)
            low[cur] = min(low[cur], dfs(el, adj, dis, low, t, inStack));
        else if (inStack[el])
            low[cur] = min(low[cur], dis[el]);
    }
    inStack[cur] = false;
    return low[cur];
}

int tarjan(int V, vector<int> adj[])
{
    vector<int> dis(V, -1);
    vector<int> low(V, -1);
    vector<bool> inStack(V, false);
    int t = 0;
    dfs(0, adj, dis, low, t, inStack);
    int count = 0;
    for (int i = 0; i < V; i++)
        count += (dis[i] == low[i]);
    return count;
}