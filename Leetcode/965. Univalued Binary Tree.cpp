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

int isUnivalTreeUtil(TreeNode *root, bool &ans)
{
    int val = root->val;
    if (!root->left && !root->right)
        return val;

    int left = val;
    if (root->left)
        left = isUnivalTreeUtil(root->left, ans);
    int right = val;
    if (root->right)
        right = isUnivalTreeUtil(root->right, ans);
    ans &= val == left;
    ans &= val == right;
    return val;
}
bool isUnivalTree(TreeNode *root)
{
    bool ans = true;
    isUnivalTreeUtil(root, ans);
    return ans;
}