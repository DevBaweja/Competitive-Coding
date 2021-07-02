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
        left = right = NULL;
    }
};

int maxPathSumUtil(Node *root, int &res)
{
    if (!root)
        return INT_MIN;
    if (!root->left && !root->right)
        return root->data;
    int l = maxPathSumUtil(root->left, res);
    int r = maxPathSumUtil(root->right, res);

    int temp = root->data + max(l, r);
    if (root->left && root->right)
    {
        int ans = root->data;
        if (l != INT_MIN)
            ans += l;
        if (r != INT_MIN)
            ans += r;
        res = max(res, ans);
    }
    return temp;
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;
    int val = maxPathSumUtil(root, res);
    if (res == INT_MIN)
        return val;
    return res;
}