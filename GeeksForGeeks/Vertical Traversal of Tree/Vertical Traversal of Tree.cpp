#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> verticalOrder(Node *root)
{
    map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *n = p.first;
            int l = p.second;
            m[l].push_back(n->data);
            if (n->left)
                q.push({n->left, l - 1});
            if (n->right)
                q.push({n->right, l + 1});
        }
    }

    vector<int> res;
    for (pair<int, vector<int>> p : m)
        for (int el : p.second)
            res.push_back(el);
    return res;
}