#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSumUtil(TreeNode *root, int &res)
{
    if (!root)
        return 0;
    int left = maxPathSumUtil(root->left, res);
    int right = maxPathSumUtil(root->right, res);
    res = max(res, root->val + max({0, left, right, left + right}));
    return root->val + max({0, left, right});
}
int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    int temp = maxPathSumUtil(root, res);
    res = max(res, temp);
    return res;
}