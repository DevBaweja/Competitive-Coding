#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int search(int in[], int el, int n)
{
    for (int i = 0; i < n; i++)
        if (in[i] == el)
            return i;
    return -1;
}

Node *buildTree(int in[], int pre[], int n)
{
    int index = search(in, pre[0], n);
    Node *root = new Node(pre[0]);
    if (index != 0)
        root->left = buildTree(in, pre + 1, index);
    if (index != n - 1)
        root->right = buildTree(in + index + 1, pre + index + 1, n - index - 1);
    return root;
}