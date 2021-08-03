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

bool isFullTree(struct Node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && root->right)
        return (isFullTree(root->left) && isFullTree(root->right));
    return false;
}