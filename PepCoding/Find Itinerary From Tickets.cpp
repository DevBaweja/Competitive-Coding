#include <bits/stdc++.h>
using namespace std;

// Hashing
int main()
{
    int n;
    cin >> n;
    unordered_set<string> reach;
    unordered_map<string, string> graph;
    for (int i = 0; i < n; i++)
    {
        string u, v;
        cin >> u >> v;
        reach.insert(v);
        graph[u] = v;
    }

    string src;
    for (pair<string, string> p : graph)
    {
        if (reach.find(p.first) == reach.end())
        {
            src = p.first;
            break;
        }
    }

    while (graph.find(src) != graph.end())
    {
        cout << src << " -> ";
        src = graph[src];
    }
    cout << src << ".";
    return 0;
}

// Hashing

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, bool> source;
    unordered_map<string, string> graph;
    for (int i = 0; i < n; i++)
    {
        string u, v;
        cin >> u >> v;
        source[v] = false;
        if (source.find(u) == source.end())
            source[u] = true;
        graph[u] = v;
    }
    string root;
    for (pair<string, bool> p : source)
    {
        if (p.second)
        {
            root = p.first;
            break;
        }
    }

    while (graph.find(root) != graph.end())
    {
        cout << root << " -> ";
        root = graph[root];
    }
    cout << root << ".";
    return 0;
}
