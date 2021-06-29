#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

Node *deleteNode(Node *root, int k)
{
    if (!root)
        return NULL;

    if (root->data == k)
        return root->left;
    else if (root->data > k)
        return deleteNode(root->left, k);
    else if (root->data < k)
        root->right = deleteNode(root->right, k);
    return root;
}