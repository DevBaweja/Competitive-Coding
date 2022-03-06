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

int findTiltUtil(TreeNode *root, int &sum)
{
    if (!root)
        return 0;
    int left = findTiltUtil(root->left, sum);
    int right = findTiltUtil(root->right, sum);
    sum += abs(left - right);
    return left + right + root->val;
}
int findTilt(TreeNode *root)
{
    int sum = 0;
    findTiltUtil(root, sum);
    return sum;
}