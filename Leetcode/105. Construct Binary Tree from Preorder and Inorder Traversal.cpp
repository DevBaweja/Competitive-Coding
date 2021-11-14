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

int search(int val, vector<int> &inorder)
{
    int n = inorder.size();
    for (int i = 0; i < n; i++)
        if (inorder[i] == val)
            return i;
    return -1;
}

TreeNode *buildTree(vector<int> preorder, vector<int> inorder)
{
    int val = preorder[0];
    int index = search(val, inorder);
    int n = inorder.size();

    TreeNode *root = new TreeNode(val);
    if (index != 0)
    {
        root->left = buildTree(
            vector<int>(preorder.begin() + 1, preorder.begin() + index + 1),
            vector<int>(inorder.begin(), inorder.begin() + index));
    }
    if (index != n - 1)
    {
        root->right = buildTree(
            vector<int>(preorder.begin() + index + 1, preorder.end()),
            vector<int>(inorder.begin() + index + 1, inorder.end()));
    }
    return root;
}

// Copying
TreeNode *buildTreeCopy(vector<int> &preorder, vector<int> &inorder)
{
    int val = preorder[0];
    int index = search(val, inorder);
    int n = inorder.size();

    TreeNode *root = new TreeNode(val);
    if (index != 0)
    {
        vector<int> p(preorder.begin() + 1, preorder.begin() + index + 1);
        vector<int> i(inorder.begin(), inorder.begin() + index);
        root->left = buildTreeCopy(p, i);
    }
    if (index != n - 1)
    {
        vector<int> p(preorder.begin() + index + 1, preorder.end());
        vector<int> i(inorder.begin() + index + 1, inorder.end());
        root->right = buildTreeCopy(p, i);
    }
    return root;
}

TreeNode *buildTreeCopy(vector<int> &preorder, vector<int> &inorder)
{
    if (!inorder.size())
        return NULL;

    int val = preorder[0];
    TreeNode *root = new TreeNode(val);
    int idx = search(val, inorder);
    vector<int> li(inorder.begin(), inorder.begin() + idx);
    vector<int> ri(inorder.begin() + idx + 1, inorder.end());
    vector<int> lp(preorder.begin() + 1, preorder.begin() + idx + 1);
    vector<int> rp(preorder.begin() + idx + 1, preorder.end());
    root->left = buildTree(lp, li);
    root->right = buildTree(rp, ri);

    return root;
}