#include <bits/stdc++.h>
using namespace std;

// Build Graph and BFS
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void distanceKUtil(TreeNode *root, unordered_map<int, vector<int>> &graph)
{
    if (!root)
        return;
    if (root->left)
    {
        distanceKUtil(root->left, graph);
        graph[root->val].push_back(root->left->val);
        graph[root->left->val].push_back(root->val);
    }
    if (root->right)
    {
        graph[root->val].push_back(root->right->val);
        graph[root->right->val].push_back(root->val);
        distanceKUtil(root->right, graph);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<int, vector<int>> graph;
    distanceKUtil(root, graph);
    unordered_set<int> vis;
    queue<int> q;
    q.push(target->val);
    vis.insert(target->val);
    while (k--)
    {
        int size = q.size();
        while (size--)
        {
            int temp = q.front();
            q.pop();
            for (int next : graph[temp])
            {
                if (vis.find(next) == vis.end())
                {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

// Ansector and Traversal
void inorder(TreeNode *root, vector<int> &result, int k)
{
    if (!root)
        return;
    if (!k)
        result.push_back(root->val);
    inorder(root->left, result, k - 1);
    inorder(root->right, result, k - 1);
}

pair<bool, int> traversalParent(TreeNode *root, TreeNode *target, int k, vector<int> &ans)
{
    if (!root)
        return {false, 0};
    if (root == target)
    {
        return {true, 1};
    }
    pair<bool, int> l = traversalParent(root->left, target, k, ans);
    if (l.first)
    {
        if (k == l.second)
            ans.push_back(root->val);
        else
            inorder(root->right, ans, k - l.second - 1);
        return {true, l.second + 1};
    }
    pair<bool, int> r = traversalParent(root->right, target, k, ans);
    if (r.first)
    {
        if (k == r.second)
            ans.push_back(root->val);
        else
            inorder(root->left, ans, k - r.second - 1);
        return {true, r.second + 1};
    }
    return {false, 0};
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> result;
    inorder(target, result, k);
    traversalParent(root, target, k, result);
    return result;
}