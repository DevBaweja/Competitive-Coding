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

Node *findPred(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}
//Function to delete a node from BST.
Node *deleteNode(Node *root, int x)
{
    if (!root)
        return root;

    if (x == root->data)
    {
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            Node *p = findPred(root->right);
            root->data = p->data;
            root->right = deleteNode(root->right, p->data);
        }
    }
    else if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    return root;
}