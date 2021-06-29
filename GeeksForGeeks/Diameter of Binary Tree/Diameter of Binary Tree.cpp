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

int diameterUtil(Node *root, int &res)
{
    if (!root)
        return 0;
    int l = diameterUtil(root->left, res);
    int r = diameterUtil(root->right, res);

    int temp = 1 + max(l, r);
    res = max(res, 1 + l + r);
    return temp;
}

int diameter(Node *root)
{
    int res = 0;
    diameterUtil(root, res);
    return res;
}