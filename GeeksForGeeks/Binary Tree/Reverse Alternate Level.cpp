#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Two Traversal
void storeAlternate(Node *root, stack<int> &s, int level)
{
    if (!root)
        return;

    storeAlternate(root->left, s, level + 1);
    if (level % 2)
        s.push(root->data);
    storeAlternate(root->right, s, level + 1);
}

void setAlternate(Node *root, stack<int> &s, int level)
{
    if (!root)
        return;

    setAlternate(root->left, s, level + 1);
    if (level % 2)
    {
        root->data = s.top();
        s.pop();
    }
    setAlternate(root->right, s, level + 1);
}

void reverseAlternate(Node *root)
{
    stack<int> s;
    storeAlternate(root, s, 0);
    setAlternate(root, s, 0);
}
