#include <bits/stdc++.h>
using namespace std;

/*
    bool DFS(int cur, vector<bool> &vis, vector<int> adj[], vector<bool> &order){
        vis[cur] = true;
        order[cur] = true;
        
        vector<int> list = adj[cur];
        for(int el: list){
            if(!vis[el] && DFS(el, vis, adj, order))
                return true;
            if(order[el])
                return true;
        }
        order[cur] = false;
        return false;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> vis(V, false);
	   	vector<bool> order(V, false);
   	    bool res = false;
	   	for(int i=0;i<V;i++)
            if(!vis[i] && DFS(i,vis,adj,order))
                return true;
        return false;
	}
*/

/*
	bool DFS(int cur, vector<bool> &vis, vector<int> adj[], vector<int> &color){
        vis[cur] = true;
        color[cur] = 0;
        
        vector<int> list = adj[cur];
        for(int el: list){
            if(!vis[el] && DFS(el, vis, adj, color))
                return true;
            if(!color[el])
                return true;
        }
        
        color[cur] = 1;
        return false;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> vis(V, false);
	   	vector<int> color(V, -1);
   	    bool res = false;
	   	for(int i=0;i<V;i++)
            if(!vis[i] && DFS(i,vis,adj,color))
                return true;
        return false;
	}
*/

// 	Using BFS Topological Sort
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> inDeg(V, 0);
    for (int i = 0; i < V; i++)
        for (int j : adj[i])
            inDeg[j]++;
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (!inDeg[i])
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            inDeg[v]--;
            if (!inDeg[v])
                q.push(v);
        }
    }

    for (int i = 0; i < V; i++)
        if (inDeg[i])
            return true;
    return false;
}