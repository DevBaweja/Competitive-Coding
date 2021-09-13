#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
Node *LCA(Node *root, int a, int b)
{
    if (!root)
        return NULL;
    if (root->data == a || root->data == b)
        return root;
    Node *l = LCA(root->left, a, b);
    Node *r = LCA(root->right, a, b);
    if (l && r)
        return root;
    if (l)
        return l;
    return r;
}

void Dist(Node *root, int key, int level, int &res)
{
    if (!root)
        return;
    if (root->data == key)
    {
        res = level;
        return;
    }

    Dist(root->left, key, level + 1, res);
    Dist(root->right, key, level + 1, res);
}

int findDist(Node *root, int a, int b)
{
    Node *lca = LCA(root, a, b);
    int resa = 0;
    Dist(root, a, 0, resa);
    int resb = 0;
    Dist(root, b, 0, resb);
    return resa + resb;
}