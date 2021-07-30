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

TreeNode *sortedArrayToBSTUtil(int left, int right, vector<int> &nums)
{
    if (left > right)
        return NULL;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTUtil(left, mid - 1, nums);
    root->right = sortedArrayToBSTUtil(mid + 1, right, nums);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    return sortedArrayToBSTUtil(left, right, nums);
}