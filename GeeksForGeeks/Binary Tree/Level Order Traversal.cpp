#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrder(Node *node)
{
    vector<vector<int>> res;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int count = q.size();
        vector<int> level;
        while (count--)
        {
            Node *temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res.push_back(level);
    }
    return res;
}
