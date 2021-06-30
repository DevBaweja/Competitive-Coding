#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
void noSiblingUtil(Node *root, vector<int> &res)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;

    if (root->left && !root->right)
        res.push_back(root->left->data);
    if (root->right && !root->left)
        res.push_back(root->right->data);

    noSiblingUtil(root->left, res);
    noSiblingUtil(root->right, res);
}

vector<int> noSibling(Node *node)
{
    vector<int> res;
    noSiblingUtil(node, res);
    if (!res.size())
        res.push_back(-1);
    sort(res.begin(), res.end());
    return res;
}