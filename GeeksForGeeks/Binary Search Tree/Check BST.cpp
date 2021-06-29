#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isBSTUtils(Node *root, int min, int max)
{
    if (!root)
        return 1;
    if (root->data < min || root->data > max)
        return 0;

    return isBSTUtils(root->left, min, root->data - 1) && isBSTUtils(root->right, root->data + 1, max);
}
bool isBST(Node *root)
{
    return isBSTUtils(root, INT_MIN, INT_MAX);
}