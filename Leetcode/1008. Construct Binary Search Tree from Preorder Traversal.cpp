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

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.empty())
        return NULL;
    int val = preorder[0];
    TreeNode *root = new TreeNode(val);
    vector<int> L, R;
    for (int i = 1; i < preorder.size(); i++)
    {
        if (preorder[i] < val)
            L.push_back(preorder[i]);
        else
            R.push_back(preorder[i]);
    }
    root->left = bstFromPreorder(L);
    root->right = bstFromPreorder(R);
    return root;
}

// Inorder and Preorder
int search(vector<int> &inorder, int inleft, int inright, int val)
{
    for (int k = inleft; k <= inright; k++)
        if (inorder[k] == val)
            return k;
    return -1;
}

TreeNode *constructTree(vector<int> preorder, vector<int> inorder, int preleft, int preright, int inleft, int inright)
{

    if (preleft > preright && inleft > inright)
        return NULL;

    int val = preorder[preleft];
    int index = search(inorder, inleft, inright, val);
    TreeNode *root = new TreeNode(val);

    if (index == -1)
        return root;
    if (index != inleft)
        root->left = constructTree(preorder, inorder, preleft + 1, index, inleft, index - 1);
    if (index != inright)
        root->right = constructTree(preorder, inorder, index + 1, preright, index + 1, inright);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    vector<int> inorder(preorder.begin(), preorder.end());
    sort(inorder.begin(), inorder.end());
    int n = inorder.size();
    return constructTree(preorder, inorder, 0, n - 1, 0, n - 1);
}
