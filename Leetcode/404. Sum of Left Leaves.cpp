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

int sumOfLeftLeavesUtil(TreeNode *root, bool side)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
    {
        if (side)
            return root->val;
        return 0;
    }

    return sumOfLeftLeavesUtil(root->left, true) + sumOfLeftLeavesUtil(root->right, false);
}

int sumOfLeftLeaves(TreeNode *root)
{
    return sumOfLeftLeavesUtil(root, false);
}