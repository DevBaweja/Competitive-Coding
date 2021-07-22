#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;

    map<Node *, Node *> m;
    queue<Node *> q;
    q.push(node);
    Node *root = new Node(node->val);
    m[node] = root;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        for (Node *v : temp->neighbors)
        {
            if (!m[v])
            {
                Node *cur = new Node(v->val);
                m[v] = cur;
                q.push(v);
            }
            m[temp]->neighbors.push_back(m[v]);
        }
    }
    return root;
}