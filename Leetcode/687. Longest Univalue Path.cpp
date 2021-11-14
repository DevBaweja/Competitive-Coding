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

pair<int, int> longestUnivaluePath(TreeNode *root, int &maxi)
{
    if (!root->left && !root->right)
        return {root->val, 1};

    int left = 0;
    if (root->left)
    {
        pair<int, int> lp = longestUnivaluePath(root->left, maxi);
        if (lp.first == root->val)
            left = lp.second;
    }
    int right = 0;
    if (root->right)
    {
        pair<int, int> rp = longestUnivaluePath(root->right, maxi);
        if (rp.first == root->val)
            right = rp.second;
    }
    maxi = max(maxi, left + right + 1);

    return {root->val, max(left, right) + 1};
}
int longestUnivaluePath(TreeNode *root)
{
    if (!root)
        return 0;
    int maxi = 1;
    longestUnivaluePath(root, maxi);
    return maxi - 1;
}