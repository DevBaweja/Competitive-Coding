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

unordered_map<int, int> traverse(TreeNode *root, int distance, int &count)
{
    if (!root)
        return unordered_map<int, int>();
    if (!root->left && !root->right)
        return unordered_map<int, int>({{1, 1}});
    unordered_map<int, int>
        left = traverse(root->left, distance, count);
    unordered_map<int, int> right = traverse(root->right, distance, count);

    for (pair<int, int> p1 : left)
    {
        for (pair<int, int> p2 : right)
        {
            if (p1.first + p2.first <= distance)
                count += p1.second * p2.second;
        }
    }
    unordered_map<int, int> res;
    for (pair<int, int> p : left)
        res[p.first + 1] += p.second;
    for (pair<int, int> p : right)
        res[p.first + 1] += p.second;
    return res;
}

int countPairs(TreeNode *root, int distance)
{
    int count = 0;
    unordered_map<int, int> m = traverse(root, distance, count);
    return count;
}