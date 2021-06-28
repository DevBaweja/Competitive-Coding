#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);
    vector<int> inDegree(v, 0);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        inDegree[y]++;
    }

    vector<int> time(v, 0);
    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
            time[i] = 1;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int k : graph[u])
        {
            inDegree[k]--;
            if (!inDegree[k])
            {
                time[k] = time[u] + 1;
                q.push(k);
            }
        }
    }

    for (int i = 0; i < v; i++)
        cout << time[i] << " ";
}