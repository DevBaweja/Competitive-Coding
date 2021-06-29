#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            Node *temp = q.front();
            q.pop();
            s.push(temp->data);
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    vector<int> res;
    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}