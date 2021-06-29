#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

bool hasPathSum(Node *root, int S)
{
    if (!root)
        return S == 0;

    return hasPathSum(root->left, S - root->data) ||
           hasPathSum(root->right, S - root->data);
}