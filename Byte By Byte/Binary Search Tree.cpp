#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Simple but Wrong
int checkBSTSimple(Node *root)
{
    if (!root)
        return 1;
    if (root->left && root->left->data > root->data)
        return 0;
    if (root->right && root->right->data < root->data)
        return 0;

    return checkBSTSimple(root->left) && checkBSTSimple(root->right);
    /*
    if (!checkBSTSimple(root->left) || !checkBSTSimple(root->right))
        return 0;

    // Passing all
    return 1;
    */
}

int maxValue(Node *root)
{
    if (!root)
        return INT_MIN;

    int res = root->data;
    int lres = maxValue(root->left);
    int rres = maxValue(root->right);

    res = max(res, max(lres, rres));
    return res;
}

int minValue(Node *root)
{
    if (!root)
        return INT_MAX;

    int res = root->data;
    int lres = minValue(root->left);
    int rres = minValue(root->right);

    res = min(res, min(lres, rres));
    return res;
}

// Correct but Ineffective
int checkBSTCorrect(Node *root)
{
    if (!root)
        return 1;
    if (root->left && maxValue(root->left) > root->data)
        return 0;
    if (root->right && minValue(root->right) < root->data)
        return 0;

    if (!checkBSTCorrect(root->left) && !checkBSTCorrect(root->right))
        return 0;

    // Passing all
    return 1;
}

int checkBSTUtils(Node *root, int min, int max)
{
    if (!root)
        return 1;

    if (root->data < min || root->data > max)
        return 0;

    return checkBSTUtils(root->left, min, root->data - 1) && checkBSTUtils(root->right, root->data + 1, max);
}

int checkBST(Node *root)
{
    return (checkBSTUtils(root, INT_MIN, INT_MAX));
}

// Time - O(n)
// Space - O(n) Call Stack

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    cout << checkBSTSimple(root) << endl;
    cout << checkBSTCorrect(root) << endl;
    cout << checkBST(root) << endl;

    return 0;
}