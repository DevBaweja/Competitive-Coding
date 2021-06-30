#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int maxHeight(Node *root)
{
    if (!root)
        return 0;
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}
void checkUtil(Node *root, int level, int height, bool *res)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        *res &= (level == height);
    checkUtil(root->left, level + 1, height, res);
    checkUtil(root->right, level + 1, height, res);
}
bool check(Node *root)
{
    int height = maxHeight(root);
    bool res = 1;
    checkUtil(root, 0, height - 1, &res);
    return res;
}