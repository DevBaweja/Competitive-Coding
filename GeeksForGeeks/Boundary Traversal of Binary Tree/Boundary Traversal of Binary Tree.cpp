#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void printLeft(Node *root, vector<int> &res)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    res.push_back(root->data);
    if (root->left)
        printLeft(root->left, res);
    else if (root->right)
        printLeft(root->right, res);
}

void printRight(Node *root, vector<int> &res)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    if (root->right)
        printRight(root->right, res);
    else if (root->left)
        printRight(root->left, res);
    res.push_back(root->data);
}

void printNode(Node *root, vector<int> &res)
{
    if (!root)
        return;
    printNode(root->left, res);
    // Leaf
    if (!root->left && !root->right)
        res.push_back(root->data);
    printNode(root->right, res);
}

vector<int> printBoundary(Node *root)
{
    if (!root)
        return {};
    vector<int> res;
    res.push_back(root->data);
    printLeft(root->left, res);
    printNode(root->left, res);
    printNode(root->right, res);
    printRight(root->right, res);
    return res;
}