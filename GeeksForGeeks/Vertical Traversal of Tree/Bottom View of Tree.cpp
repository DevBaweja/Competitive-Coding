#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
{

    map<int, int> m;
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
            m[l] = n->data;
            if (n->left)
                q.push({n->left, l - 1});
            if (n->right)
                q.push({n->right, l + 1});
        }
    }

    vector<int> res;
    for (pair<int, int> p : m)
        res.push_back(p.second);
    return res;
}
