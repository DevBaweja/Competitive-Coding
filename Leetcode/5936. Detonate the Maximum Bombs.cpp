#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool getDistance(vector<int> a, vector<int> b)
{
    ll dist = pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2);
    double req = sqrt(dist);
    return req <= (double)a[2];
}
/*
    int detonation(int init, vector<vector<int>>& bombs, int n){
        vector<bool> vis(n, false);
        vis[init] = true;
        queue<int> q;
        q.push(init);
        int count = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            count++;
            for(int next=0; next<n; next++){
                if(!vis[next] && getDistance(bombs[cur], bombs[next])){
                    q.push(next);
                    vis[next] = true;
                }
            }
        }
        return count;
    }
    */

int dfs(int cur, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[cur] = true;
    int count = 1;
    for (int next : graph[cur])
        if (!vis[next])
            count += dfs(next, graph, vis);
    return count;
}

int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    // unordered_map<int, vector<int>> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (getDistance(bombs[i], bombs[j]))
                graph[i].push_back(j);

    for (vector<int> v : graph)
    {
        for (int el : v)
            cout << el << " ";
        cout << endl;
    }
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        vector<bool> vis(n, false);
        maxi = max(maxi, dfs(i, graph, vis));
    }
    return maxi;
}