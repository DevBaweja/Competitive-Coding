#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &dist)
{
    int V = dist.size();
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] != -1 && dist[k][j] != -1 &&
                    dist[i][j] > (dist[i][k] + dist[k][j]))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}