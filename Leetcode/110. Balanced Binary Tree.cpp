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

int isBalancedUtil(TreeNode *root, bool &res)
{
    if (!root)
        return 0;
    int l = isBalancedUtil(root->left, res);
    int r = isBalancedUtil(root->right, res);
    if (abs(l - r) > 1)
        res = false;
    return 1 + max(l, r);
}

bool isBalanced(TreeNode *root)
{
    bool res = true;
    isBalancedUtil(root, res);
    return res;
}
