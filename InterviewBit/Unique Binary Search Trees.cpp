#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> constructTree(int start, int end)
{
    vector<TreeNode *> list;
    if (start > end)
    {
        list.push_back(NULL);
        return list;
    }

    for (int k = start; k <= end; k++)
    {
        vector<TreeNode *> left = constructTree(start, k - 1);
        vector<TreeNode *> right = constructTree(k + 1, end);

        for (int i = 0; i < left.size(); i++)
        {
            TreeNode *l = left[i];
            for (int j = 0; j < right.size(); j++)
            {
                TreeNode *r = right[j];
                TreeNode *n = new TreeNode(k);
                n->left = l;
                n->right = r;
                list.push_back(n);
            }
        }
    }
    return list;
}

vector<TreeNode *> generateTrees(int n)
{
    return constructTree(1, n);
}
