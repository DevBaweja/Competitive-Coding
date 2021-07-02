#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

bool Traversal(Node *root, int target, vector<int> &path)
{
    if (!root)
        return false;
    if (root->data == target)
        return true;

    if (Traversal(root->left, target, path) ||
        Traversal(root->right, target, path))
        path.push_back(root->data);
}
vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> path;
    Traversal(root, target, path);
    return path;
}