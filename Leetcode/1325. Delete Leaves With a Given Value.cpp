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

// Replace and Remove
void removeLeafNodesUtil(TreeNode *root, int target)
{
    if (!root)
        return;

    removeLeafNodesUtil(root->left, target);
    removeLeafNodesUtil(root->right, target);

    if (root->val == target && (!root->left || root->left->val == -1) &&
        (!root->right || root->right->val == -1))
        root->val = -1;
}

TreeNode *removeLeafNodesRemove(TreeNode *root)
{
    if (!root)
        return NULL;
    if (root->val == -1)
        return NULL;
    root->left = removeLeafNodesRemove(root->left);
    root->right = removeLeafNodesRemove(root->right);
    return root;
}

TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    removeLeafNodesUtil(root, target);
    return removeLeafNodesRemove(root);
}

// Optimial
TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    if (!root)
        return root;

    root->left = removeLeafNodes(root->left, target);

    root->right = removeLeafNodes(root->right, target);

    if (!root->left && !root->right && root->val == target)
        return NULL;

    return root;
}