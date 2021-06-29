#include <bits/stdc++.h>
using namespace std;

string TopologicalSort(vector<vector<int>> &graph, int k)
{
    vector<int> inDegree(k, 0);
    for (int i = 0; i < k; i++)
        for (int j : graph[i])
            inDegree[j]++;

    queue<int> q;
    for (int i = 0; i < k; i++)
        if (!inDegree[i])
            q.push(i);

    string res = "";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res += (u + 'a');
        for (int v : graph[u])
        {
            inDegree[v]--;
            if (!inDegree[v])
                q.push(v);
        }
    }
    return res;
}

string findOrder(string dict[], int n, int k)
{
    vector<vector<int>> graph(k);
    for (int i = 0; i < n - 1; i++)
    {
        string a = dict[i];
        string b = dict[i + 1];
        for (int j = 0; j < min(a.size(), b.size()); j++)
        {
            if (a[j] != b[j])
            {
                graph[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }

    return TopologicalSort(graph, k);
}

int main()
{
    int n = 5, k = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << findOrder(dict, n, k);
    return 0;
}