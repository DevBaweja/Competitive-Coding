#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *findPred(TreeNode *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;
    if (key == root->val)
    {
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            TreeNode *p = findPred(root->right);
            root->val = p->val;
            root->right = deleteNode(root->right, p->val);
        }
    }
    else if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    return root;
}