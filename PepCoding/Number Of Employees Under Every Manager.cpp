#include <bits/stdc++.h>
using namespace std;

int getCount(unordered_map<string, unordered_set<string>> &tree, string root, map<string, int> &res)
{
    if (tree.find(root) == tree.end())
    {
        res[root] = 0;
        return 1;
    }

    int size = 0;
    for (string other : tree[root])
        size += getCount(tree, other, res);

    res[root] = size;
    return size + 1;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<string, unordered_set<string>> tree;
    string root;
    for (int i = 0; i < n; i++)
    {
        string u, v;
        cin >> u >> v;
        if (u == v)
            root = u;
        else
            tree[v].insert(u);
    }

    map<string, int> res;

    getCount(tree, root, res);

    for (pair<string, int> p : res)
        cout << p.first << " " << p.second << endl;

    return 0;
}