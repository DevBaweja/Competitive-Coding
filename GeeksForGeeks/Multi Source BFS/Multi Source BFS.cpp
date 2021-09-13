#include <bits/stdc++.h>
using namespace std;

int maxCost(int n, int m, vector<int> &A, vector<int> &B, vector<int> &H)
{
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int u = A[i];
        int v = B[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vector<int> vis(n, 0);
    for (int i = 0; i < m; i++)
    {
        int el = H[i];
        q.push({el, 0});
        vis[el] = 1;
    }
    int res = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int u = p.first;
            int t = p.second;
            res = t;
            for (int v : graph[u])
            {
                if (!vis[v])
                {
                    q.push({v, t + 1});
                    vis[v] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (!vis[i])
            return -1;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<int> A(e);
    vector<int> B(e);
    for (int i = 0; i < e; i++)
        cin >> A[i];
    for (int i = 0; i < e; i++)
        cin >> B[i];
    int m;
    cin >> m;
    vector<int> H(m);
    for (int i = 0; i < m; i++)
        cin >> H[i];

    cout << maxCost(n, m, A, B, H);
    return 0;
}