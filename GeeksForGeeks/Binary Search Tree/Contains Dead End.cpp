#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

bool isDeadEndUtil(Node *root, int mini, int maxi)
{
    if (!root)
        return false;
    if (mini == maxi)
        return true;
    return isDeadEndUtil(root->left, mini, root->data - 1) ||
           isDeadEndUtil(root->right, root->data + 1, maxi);
}
bool isDeadEnd(Node *root)
{
    return isDeadEndUtil(root, 1, INT_MAX);
}