#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// BFS
vector<int> bottomView(Node *root)
{
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *temp = p.first;
            int level = p.second;
            m[level] = temp->data;
            if (temp->left)
                q.push({temp->left, level - 1});
            if (temp->right)
                q.push({temp->right, level + 1});
        }
    }
    vector<int> res;
    for (pair<int, int> el : m)
        res.push_back(el.second);
    return res;
}

// DFS
void bottomViewUtil(Node *root, map<int, pair<int, int>> &m, int level, int height)
{
    if (!root)
        return;
    bottomViewUtil(root->left, m, level - 1, height + 1);
    bottomViewUtil(root->right, m, level + 1, height + 1);
    if (m.find(level) != m.end())
    {
        pair<int, int> p = m[level];
        if (p.second > height)
            return;
    }
    m[level].first = root->data;
    m[level].second = height;
}

vector<int> bottomView(Node *root)
{
    map<int, pair<int, int>> m;
    vector<int> res;
    bottomViewUtil(root, m, 0, 0);
    for (pair<int, pair<int, int>> el : m)
        res.push_back(el.second.first);
    return res;
}