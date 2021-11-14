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

TreeNode *lca(TreeNode *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->val == n1 || root->val == n2)
        return root;

    TreeNode *l = lca(root->left, n1, n2);
    TreeNode *r = lca(root->right, n1, n2);
    if (l && r)
        return root;
    if (l)
        return l;
    return r;
}

// Multiple LCA
TreeNode *lcaDeepestLeaves(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<TreeNode *> res;
    while (!q.empty())
    {
        int size = q.size();
        vector<TreeNode *> v(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            v[i] = temp;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res = v;
    }
    if (res.size() == 1)
        return res[0];
    TreeNode *ft = lca(root, res[0]->val, res[1]->val);
    for (int i = 2; i < res.size(); i++)
        ft = lca(root, ft->val, res[i]->val);
    return ft;
}

// Using Set or Map and LCA
// Bit Manipulation
bool search(vector<TreeNode *> &res, int val)
{
    int n = res.size();
    for (TreeNode *el : res)
        if (el->val == val)
            return true;
    return false;
}

unordered_set<int> lca(TreeNode *root, vector<TreeNode *> &res, TreeNode *&ans)
{
    if (!root)
        return unordered_set<int>();
    unordered_set<int> l = lca(root->left, res, ans);
    unordered_set<int> r = lca(root->right, res, ans);

    unordered_set<int> s;
    for (int el : l)
        s.insert(el);
    for (int el : r)
        s.insert(el);
    if (search(res, root->val))
        s.insert(root->val);
    if (s.size() == res.size() && !ans)
        ans = root;

    return s;
}

TreeNode *lcaDeepestLeaves(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<TreeNode *> res;
    while (!q.empty())
    {
        int size = q.size();
        vector<TreeNode *> v(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            v[i] = temp;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res = v;
    }
    TreeNode *ans = NULL;
    lca(root, res, ans);
    return ans;
}