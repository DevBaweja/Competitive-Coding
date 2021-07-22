#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// Doesn't work
vector<int> zigZagTraversal(Node *root)
{
    if (!root)
        return {};
    queue<Node *> q;
    q.push(root);
    int flag = false;
    vector<int> res;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            Node *temp = q.front();
            q.pop();
            res.push_back(temp->data);
            if (flag)
            {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else
            {
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        flag = !flag;
    }
    return res;
}
// Using Two Stack
vector<int> zigZagTraversal(Node *root)
{
    if (!root)
        return {};
    stack<Node *> current;
    stack<Node *> next;
    current.push(root);
    int flag = true;
    vector<int> res;
    while (!current.empty())
    {
        int count = current.size();
        while (count--)
        {
            Node *temp = current.top();
            current.pop();
            res.push_back(temp->data);
            if (flag)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
        }
        flag = !flag;
        swap(current, next);
    }
    return res;
}