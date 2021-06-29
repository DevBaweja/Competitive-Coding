#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *random;
};

Node *Copying(Node *tree, unordered_map<Node *, Node *> &m)
{
    if (!tree)
        return tree;
    Node *copy = new Node(tree->data);
    m[tree] = copy;
    copy->left = Copying(tree->left, m);
    copy->right = Copying(tree->right, m);
    return copy;
}

void Random(Node *tree, Node *copy, unordered_map<Node *, Node *> &m)
{
    if (!copy)
        return;
    if (tree->random)
        copy->random = m[tree->random];
    Random(tree->left, copy->left, m);
    Random(tree->right, copy->right, m);
}

Node *cloneTree(Node *tree)
{
    if (!tree)
        return tree;

    unordered_map<Node *, Node *> m;
    Node *copy = Copying(tree, m);
    Random(tree, copy, m);
    return copy;
}