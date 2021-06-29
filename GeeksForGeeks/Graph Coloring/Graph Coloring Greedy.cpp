#include <bits/stdc++.h>
using namespace std;

vector<int> colorGraph(int v, vector<vector<int>> graph)
{
    int cn = 0;
    vector<int> colors(v, -1);
    for (int i = 0; i < v; i++)
    {
        vector<bool> available(v, true);
        for (int j : graph[i])
        {
            if (colors[j] != -1)
                available[colors[j]] = false;
        }

        int cr;
        for (cr = 0; cr < v; cr++)
        {
            if (available[cr])
                break;
        }

        colors[i] = cr;
        cn = max(cn, cr);
    }
    return colors;
}

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

    vector<int> colors = colorGraph(v, graph);

    for (int i = 0; i < v; i++)
        cout << colors[i] << " ";
}