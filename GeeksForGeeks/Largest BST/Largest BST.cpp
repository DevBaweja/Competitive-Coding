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

struct Info
{
    bool isBst;
    int mini;
    int maxi;
    int size;
};

Info largestBstUtil(Node *root, int &res)
{
    if (!root)
        return {true, INT_MAX, INT_MIN, 0};

    if (!root->left && !root->right)
        return {true, root->data, root->data, 1};

    Info l = largestBstUtil(root->left, res);
    Info r = largestBstUtil(root->right, res);

    if (l.isBst && r.isBst && l.maxi < root->data && r.mini > root->data)
    {
        res = max(res, l.size + r.size + 1);
        return {true,
                min({l.mini, r.mini, root->data}),
                max({r.maxi, l.maxi, root->data}), l.size + r.size + 1};
    }

    return {false, 0, 0, 0};
}

int largestBst(Node *root)
{
    if (!root)
        return 0;
    int res = 1;
    largestBstUtil(root, res);
    return res;
}