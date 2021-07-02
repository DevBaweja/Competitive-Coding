#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void Traversal(Node *root, vector<int> path, vector<vector<int>> &res)
{
    if (!root)
        return;
    path.push_back(root->data);
    if (!root->left && !root->right)
        res.push_back(path);
    Traversal(root->left, path, res);
    Traversal(root->right, path, res);
}

vector<vector<int>> Paths(Node *root)
{
    vector<int> path;
    vector<vector<int>> res;
    Traversal(root, path, res);
    return res;
}