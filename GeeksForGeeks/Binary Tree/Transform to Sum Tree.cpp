#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int toSumTreeUtil(Node *root)
{
    if (!root)
        return 0;

    int old = root->data;

    int lsum = toSumTreeUtil(root->left);
    int rsum = toSumTreeUtil(root->right);

    root->data = lsum + rsum;
    return root->data + old;
}
// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
void toSumTree(Node *node)
{
    toSumTreeUtil(node);
}