#include <bits/stdc++.h>
using namespace std;

// Get Min Distance
/*
	int minDistance(int V, vector<int> distance, vector<bool> spt){
	    int minimum = INT_MAX, minimumIndex = -1;
	    for(int u=0;u<V;u++){
	        if(!spt[u] && distance[u] <= minimum){
	            minimum = distance[u];
	            minimumIndex = u;
	        }
	    }
	    return minimumIndex;
	}
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, INT_MAX);
        vector<bool> spt(V, false);
        
        distance[S] = 0;
        
        for(int count=0;count<V-1;count++){
            int u = minDistance(V, distance, spt);
            spt[u] = true;
            vector<vector<int>> list = adj[u];
            for(vector<int> el : list){
                int v = el[0];
                int w = el[1];
                if(distance[u] != INT_MAX && !spt[v] &&
                distance[u]+w < distance[v])
                    distance[v] = distance[u]+w;
            }
        }
        return distance;
    }
*/

// Using set
void getPath(vector<int> parent, int i, int S, vector<int> &path)
{
    if (parent[i] == -1)
    {
        path.push_back(S);
        return;
    }
    getPath(parent, parent[i], S, path);
    path.push_back(i);
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V, INT_MAX);
    vector<int> parent(V, -1);
    set<pair<int, int>> spt;
    spt.insert({0, S});
    distance[S] = 0;

    while (!spt.empty())
    {
        pair<int, int> temp = *(spt.begin());
        spt.erase(spt.begin());

        int u = temp.second;
        vector<vector<int>> list = adj[u];
        for (vector<int> el : list)
        {
            int v = el[0];
            int w = el[1];
            if (distance[u] != INT_MAX &&
                distance[u] + w < distance[v])
            {
                if (distance[v] != INT_MAX)
                    spt.erase(spt.find({distance[v], v}));
                distance[v] = distance[u] + w;
                parent[v] = u;
                spt.insert({distance[v], v});
            }
        }
    }

    vector<vector<int>> paths;
    for (int i = 0; i < V; i++)
    {
        vector<int> path;
        getPath(parent, i, S, path);
        paths.push_back(path);
    }
    return distance;
}

// Using Priority Queue
/*
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, INT_MAX);
        
        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;
        
        pq.push({0,S});
        distance[S] = 0;
        
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            
            int u = temp.second;
            vector<vector<int>> list = adj[u];
            for(vector<int> el: list){
                int v = el[0];
                int w = el[1];
                if(distance[u] != INT_MAX && 
                distance[u]+w < distance[v]){
                    distance[v] = distance[u]+w;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance;
    }
*/