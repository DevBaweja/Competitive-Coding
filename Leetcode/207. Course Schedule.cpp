#include <bits/stdc++.h>
using namespace std;

// Cyclic DFS Order
bool DFS(int cur, vector<vector<int>> &graph, vector<bool> &order, vector<bool> &vis){
        vis[cur] = true;
        order[cur] = true;
        
        for(int el: graph[cur]){
            if(!vis[el] && DFS(el, graph, order, vis))
                return true;
            if(order[el])
                return true;
        }
        order[cur] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(vector<int> el: edges)
            graph[el[0]].push_back(el[1]);
        
        vector<bool> vis(n, false);
        vector<bool> order(n, false);
        
        for(int i=0; i<n; i++)
            if(!vis[i] && DFS(i, graph, order, vis))
                return false;
        return true;
    }

// Cyclic BFS Topological
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