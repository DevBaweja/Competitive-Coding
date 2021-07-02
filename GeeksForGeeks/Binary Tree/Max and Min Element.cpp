#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int findMax(Node *root)
{
    if (!root)
        return INT_MIN;
    if (!root->left && !root->right)
        return root->data;
    return max({root->data,
                findMax(root->left),
                findMax(root->right)});
}
int findMin(Node *root)
{
    if (!root)
        return INT_MAX;
    if (!root->left && !root->right)
        return root->data;
    return min({root->data,
                findMin(root->left),
                findMin(root->right)});
}