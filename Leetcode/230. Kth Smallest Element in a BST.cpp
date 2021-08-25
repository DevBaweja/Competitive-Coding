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

// Time - n
// Space - n
void Traversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    Traversal(root->left, res);
    res.push_back(root->val);
    Traversal(root->right, res);
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> res;
    Traversal(root, res);
    return res[k - 1];
}

// Time - n
// Space - h
int kthSmallestUtil(TreeNode *root, int &k)
{
    if (!root)
        return 0;
    int l = kthSmallestUtil(root->left, k);
    if (l)
        return l;

    k--;
    if (!k)
        return root->val;

    int r = kthSmallestUtil(root->right, k);
    if (r)
        return r;

    return 0;
}

// Time - k
// Space - h
int kthSmallestItervative(TreeNode *root, int &k)
{
    stack<TreeNode *> s;
    TreeNode *temp = root;
    while (true)
    {
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        k--;
        if (!k)
            return temp->val;
        temp = temp->right;
    }
}