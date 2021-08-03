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

// Two Pass
int maxHeight(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}

void sumNodes(TreeNode *root, int &sum, int level, int maxLevel)
{
    if (!root)
        return;
    sumNodes(root->left, sum, level + 1, maxLevel);
    if (level == maxLevel)
        sum += root->val;
    sumNodes(root->right, sum, level + 1, maxLevel);
}

int deepestLeavesSum(TreeNode *root)
{
    int maxLevel = maxHeight(root);
    int sum = 0, level = 1;
    sumNodes(root, sum, level, maxLevel);
    return sum;
}

// One Pass
void traversal(TreeNode *root, int level, int &maxLevel, int &sum)
{
    if (!root)
        return;
    if (level == maxLevel)
    {
        sum += root->val;
    }
    else if (level > maxLevel)
    {
        sum = root->val;
        maxLevel = level;
    }
    traversal(root->left, level + 1, maxLevel, sum);
    traversal(root->right, level + 1, maxLevel, sum);
}

int deepestLeavesSum(TreeNode *root)
{
    int sum = 0, maxLevel = 0;
    traversal(root, 0, maxLevel, sum);
    return sum;
}