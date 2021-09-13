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

int findMaxSumUtil(Node *root, int &res)
{
    if (!root)
        return 0;

    int l = findMaxSumUtil(root->left, res);
    int r = findMaxSumUtil(root->right, res);

    int temp = max(root->data, root->data + max(l, r));
    int ans = max(temp, l + r + root->data);

    res = max(res, ans);

    return temp;
}

int findMaxSum(Node *root)
{
    int res = INT_MIN;
    int ans = findMaxSumUtil(root, res);
    res = max(res, ans);
    return res;
}