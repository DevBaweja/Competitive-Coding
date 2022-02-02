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

TreeNode *delNodesUtil(TreeNode *root, unordered_set<int> &mp, vector<TreeNode *> &res)
{
    if (!root)
        return NULL;

    if (mp.find(root->val) != mp.end())
    {
        root->left = delNodesUtil(root->left, mp, res);
        if (root->left)
            res.push_back(root->left);
        root->right = delNodesUtil(root->right, mp, res);
        if (root->right)
            res.push_back(root->right);
        return NULL;
    }
    root->left = delNodesUtil(root->left, mp, res);
    root->right = delNodesUtil(root->right, mp, res);
    return root;
}

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &del)
{
    vector<TreeNode *> res;
    unordered_set<int> mp;
    for (int el : del)
        mp.insert(el);
    root = delNodesUtil(root, mp, res);
    if (root)
    {
        if (mp.find(root->val) != mp.end())
        {
            if (root->left)
                res.push_back(root->left);
            if (root->right)
                res.push_back(root->right);
        }
        res.push_back(root);
    }

    return res;
}