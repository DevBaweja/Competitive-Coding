#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

Node *findPred(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

int height(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

void updateHeight(Node *root)
{
    root->height = 1 + max(height(root->left), height(root->right));
}

int getBalance(Node *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t = y->left;
    y->left = x;
    x->right = t;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    Node *t = y->right;
    y->right = x;
    x->left = t;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node *deleteNode(Node *root, int data)
{
    // Delete BST
    if (!root)
        return root;
    if (data == root->data)
    {
        if (!root->left && !root->right)
            return NULL;
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;
        Node *p = findPred(root->right);
        root->data = p->data;
        root->right = deleteNode(root->right, p->data);
    }
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // AVL Balancing
    if (!root)
        return root;

    updateHeight(root);
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    // LR
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    // RL
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}