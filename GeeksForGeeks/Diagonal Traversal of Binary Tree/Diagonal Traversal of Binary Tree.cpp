#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// BFS Iterative
vector<int> diagonal(Node *root)
{
    if (!root)
        return {};

    vector<int> res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            res.push_back(temp->data);
            temp = temp->right;
        }
    }
    return res;
}

// Hashing
vector<int> diagonal(Node *root)
{
    if (!root)
        return {};
    map<int, vector<int>> m;

    vector<int> res;
    queue<pair<int, Node *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        pair<int, Node *> p = q.front();
        q.pop();
        int level = p.first;
        Node *temp = p.second;
        m[level].push_back(temp->data);
        if (temp->right)
            q.push({level, temp->right});
        if (temp->left)
            q.push({level + 1, temp->left});
    }

    for (pair<int, vector<int>> p : m)
    {
        for (int el : p.second)
            res.push_back(el);
    }
    return res;
}