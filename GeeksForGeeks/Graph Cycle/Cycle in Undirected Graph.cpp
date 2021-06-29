#include <bits/stdc++.h>
using namespace std;

// By adding Order in DFS
// Works for directed graph
/*
	bool DFS(int cur, vector<bool> &vis, vector<int> adj[], vector<bool> &order){
        vis[cur] = true;
        order[cur] = true;
        
        vector<int> list = adj[cur];
        for(int el: list){
            if(!vis[el])
            {    
                DFS(el, vis, adj, order))
                return true;
            }
            else if(order[el])
                return true;
        }
        order[cur] = false;
        return false;
    }
    
	bool isCycle(int V, vector<int> adj[]) 
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

// DFS
// 	Remove Order and Add parent
/*
    bool DFS(int cur, vector<bool> &vis, vector<int> adj[], int parent){
        vis[cur] = true;
        vector<int> list = adj[cur];
        for(int el: list){
            if(!vis[el])
            { 
                if(DFS(el, vis, adj, cur))
                    return true;
            }
            else if(el != parent)
                return true;
        }
        return false;
    }
    
	bool isCycle(int V, vector<int> adj[]) 
	{
	   	vector<bool> vis(V, false);
   	    bool res = false;
	   	for(int i=0;i<V;i++)
            if(!vis[i] && DFS(i,vis,adj,-1))
                return true;
        return false;
	}
*/

// BFS Using Parent
/*
	bool BFS(int root, vector<bool> &vis, vector<int> adj[], vector<int> &parent)
    {
        queue<int> q;
        vis[root] = true;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            vector<int> list = adj[cur];
            for (int el: list) {
                if (!vis[el]) {
                    vis[el] = true;
                    q.push(el);
                    parent[el] = cur;
                }
                else if (parent[cur] != el)
                    return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int> adj[]){
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);
         
            for (int i = 0; i < V; i++)
                if (!vis[i] && BFS(i, vis, adj, parent))
                    return true;
            return false;
	}
*/

// BFS Color
/*
	bool BFS(int root, vector<int> &color, vector<int> adj[]){
	    queue<int> q;
	    q.push(root);
	    color[root] = 0;
	    while(!q.empty()){
	        int cur = q.front();
	        q.pop();
	        vector<int> list = adj[cur];
	        color[cur] = 1;
	        for(int el: list)
	        {
	            if(!color[el])
	                return true;
	            if(color[el] == 1)
    	            continue;
                q.push(el);
	            color[el] = 0;
	        }
	    }
	    return false;
	}
	bool isCycle(int V, vector<int> adj[]) 
	{
	   	vector<int> color(V, -1);
   	    bool res = false;
	   	for(int i=0;i<V;i++)
            if(color[i] == -1 && BFS(i,color,adj))
                return true;
        return false;
	}
*/

// Find-Union
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

bool isCycle(int V, vector<int> adj[])
{

    set<pair<int, int>> edges;
    for (int x = 0; x < V; x++)
        for (int y : adj[x])
            edges.insert({min(x, y), max(x, y)});

    vector<int> parent(V, -1);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<int> rank(V, 0);
    for (pair<int, int> edge : edges)
    {
        int x = edge.first;
        int y = edge.second;
        int xset = Find(parent, x);
        int yset = Find(parent, y);
        if (xset == yset)
            return true;
        Union(parent, rank, xset, yset);
    }
    return false;
}