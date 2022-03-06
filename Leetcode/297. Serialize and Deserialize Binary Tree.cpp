#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serializeUtil(TreeNode *root, string &res)
{
    if (!root)
    {
        res += "*";
        return;
    }
    res += to_string(root->val) + ",";
    serializeUtil(root->left, res);
    serializeUtil(root->right, res);
}

string serialize(TreeNode *root)
{
    string res = "";
    serializeUtil(root, res);
    return res;
}

TreeNode *deserializeUtil(string &data, int &index)
{
    if (index == data.size())
        return NULL;
    if (data[index] == '*')
    {
        index++;
        return NULL;
    }
    int val = 0;
    bool neg = false;
    while (data[index] != ',')
    {
        if (data[index] == '-')
        {
            neg = true;
            index++;
            continue;
        }
        val = val * 10 + (data[index++] - '0');
    }
    if (neg)
        val = -val;
    index++;
    TreeNode *root = new TreeNode(val);
    root->left = deserializeUtil(data, index);
    root->right = deserializeUtil(data, index);
    return root;
}

TreeNode *deserialize(string data)
{
    int index = 0;
    TreeNode *root = deserializeUtil(data, index);
    return root;
}