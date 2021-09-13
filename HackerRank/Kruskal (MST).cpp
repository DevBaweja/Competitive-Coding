#include <bits/stdc++.h>
using namespace std;

int Find(vector<int> &parent, int x)
{
    if (parent[x] == -1)
        return x;
    return Find(parent, parent[x]);
}

void Union(vector<int> &parent, int x, int y)
{
    int fx = Find(parent, x);
    int fy = Find(parent, y);
    parent[fx] = fy;
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<pair<int, pair<int, int>>> edges(e);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(n, -1);
    int cost = 0;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        int x = Find(parent, u);
        int y = Find(parent, v);
        if (x != y)
        {
            Union(parent, x, y);
            cost += w;
        }
    }
    cout << cost << endl;
    return 0;
}