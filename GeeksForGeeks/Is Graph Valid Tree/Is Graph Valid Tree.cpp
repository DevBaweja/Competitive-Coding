#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int cur, int parent, vector<vector<int>> &graph, vector<int> &vis)
{
    vis[cur] = 1;
    for (int next : graph[cur])
    {
        if (!vis[next])
        {
            if (detectCycle(next, cur, graph, vis))
                return true;
        }
        else if (next != parent)
            return true;
    }
    return false;
}

bool isValidTree(int n, vector<vector<int>> &graph)
{
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            detectCycle(i, -1, graph, vis);
            count++;
        }
    }
    return count == 1;
}

//  No Cycle and Connected
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << isValidTree(v, graph);
}
