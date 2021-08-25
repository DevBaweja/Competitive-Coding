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

int search(vector<pair<int, int>> v, int key)
{
    for (pair<int, int> t : v)
        if (t.first == key)
            return t.second;
    return 0;
}

bool isCousins(TreeNode *root, int x, int y)
{
    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({root, new TreeNode(-1)});
    while (!q.empty())
    {
        int count = q.size();
        vector<pair<int, int>> v(count);
        for (int k = 0; k < count; k++)
        {
            pair<TreeNode *, TreeNode *> temp = q.front();
            TreeNode *el = temp.first;
            TreeNode *p = temp.second;
            q.pop();
            v[k] = {el->val, p->val};
            if (el->left)
                q.push({el->left, el});
            if (el->right)
                q.push({el->right, el});
        }
        int resx = search(v, x);
        int resy = search(v, y);
        if (!resx && !resy)
            continue;
        if (!resx || !resy)
            return false;
        if (resx == resy)
            return false;
        return true;
    }
    return false;
}