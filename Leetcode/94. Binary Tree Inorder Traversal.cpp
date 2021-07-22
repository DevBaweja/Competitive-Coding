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

// Iterative
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> s;
    TreeNode *current = root;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top()->right;
        v.push_back(s.top()->val);
        s.pop();
    }
    return v;
}

// Recursive
void inorderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    inorderTraversal(root, res);
    return res;
}