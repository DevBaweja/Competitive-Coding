#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int isSum(Node *root, bool *sum)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;

    int temp = root->data;
    int lsum = 0, rsum = 0;
    if (root->left)
        lsum = isSum(root->left, sum);
    if (root->right)
        rsum = isSum(root->right, sum);
    if (root->data != lsum + rsum)
        *sum = false;
    return lsum + rsum + temp;
}

bool isSumTree(Node *root)
{
    bool res = true;
    int sum = isSum(root, &res);
    return res;
}