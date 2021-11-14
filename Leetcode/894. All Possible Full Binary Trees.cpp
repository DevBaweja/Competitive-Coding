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

vector<TreeNode *> allPossibleFBT(int n)
{
    if (n == 1)
    {
        TreeNode *root = new TreeNode(0);
        return {root};
    }

    vector<TreeNode *> trees;
    for (int leftNode = 1; leftNode < n; leftNode += 2)
    {
        int rightNode = n - leftNode - 1;
        vector<TreeNode *> leftTrees = allPossibleFBT(leftNode);
        vector<TreeNode *> rightTrees = allPossibleFBT(rightNode);

        for (TreeNode *leftTree : leftTrees)
        {
            for (TreeNode *rightTree : rightTrees)
            {
                TreeNode *root = new TreeNode(0);
                root->left = leftTree;
                root->right = rightTree;
                trees.push_back(root);
            }
        }
    }

    return trees;
}

// Memo
vector<TreeNode *> allPossibleFBTMemo(int n, unordered_map<int, vector<TreeNode *>> &m)
{
    if (n == 1)
    {
        TreeNode *root = new TreeNode(0);
        return {root};
    }
    if (m.find(n) != m.end())
        return m[n];

    vector<TreeNode *> trees;
    for (int leftNode = 1; leftNode < n; leftNode += 2)
    {
        int rightNode = n - leftNode - 1;
        vector<TreeNode *> leftTrees = allPossibleFBTMemo(leftNode, m);
        vector<TreeNode *> rightTrees = allPossibleFBTMemo(rightNode, m);

        for (TreeNode *leftTree : leftTrees)
        {
            for (TreeNode *rightTree : rightTrees)
            {
                TreeNode *root = new TreeNode(0);
                root->left = leftTree;
                root->right = rightTree;
                trees.push_back(root);
            }
        }
    }
    m[n] = trees;
    return m[n];
}

vector<TreeNode *> allPossibleFBT(int n)
{
    unordered_map<int, vector<TreeNode *>> m;
    return allPossibleFBTMemo(n, m);
}