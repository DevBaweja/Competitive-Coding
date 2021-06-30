#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *nextRight(Node *root, int key)
{
    queue<pair<int, Node *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<int, Node *> temp = q.front();
            q.pop();

            if (temp.second->data == key)
            {
                if (q.empty() ||
                    q.front().first != temp.first)
                    return new Node(-1);
                return q.front().second;
            }

            if (temp.second->left)
                q.push({temp.first + 1, temp.second->left});
            if (temp.second->right)
                q.push({temp.first + 1, temp.second->right});
        }
    }
    return new Node(-1);
}