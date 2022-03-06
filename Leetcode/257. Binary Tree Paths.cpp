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

void binaryTreePathsUtil(TreeNode *root, string path, vector<string> &res)
{
    if (!root)
        return;

    path += "->" + to_string(root->val);
    if (!root->left && !root->right)
    {
        res.push_back(path);
        return;
    }
    binaryTreePathsUtil(root->left, path, res);
    binaryTreePathsUtil(root->right, path, res);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    if (!root)
        return {};
    vector<string> res;
    string path = to_string(root->val);
    if (!root->left && !root->right)
        res.push_back(path);
    if (root->left)
        binaryTreePathsUtil(root->left, path, res);
    if (root->right)
        binaryTreePathsUtil(root->right, path, res);
    return res;
}

void binaryTreePathsUtil(TreeNode *root, string path, vector<string> &res)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        res.push_back(path + to_string(root->val));
        return;
    }
    binaryTreePathsUtil(root->left, path + to_string(root->val) + "->", res);
    binaryTreePathsUtil(root->right, path + to_string(root->val) + "->", res);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    if (!root)
        return {};
    vector<string> res;
    string path = "";
    binaryTreePathsUtil(root, path, res);
    return res;
}