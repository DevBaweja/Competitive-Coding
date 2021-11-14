#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int search(int val, vector<int> &order)
{
    int n = order.size();
    for (int i = 0; i < n; i++)
        if (val == order[i])
            return i;
    return -1;
}

// Recursive
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n1 = preorder.size();
    int n2 = postorder.size();

    if (!n1 || !n2)
        return NULL;
    if (n1 == 1)
        return new TreeNode(preorder[0]);
    if (n2 == 1)
        return new TreeNode(postorder[n2 - 1]);

    int valpre = preorder[1];
    int valpost = postorder[n2 - 2];

    int indexpre = search(valpost, preorder);
    int indexpost = search(valpre, postorder);

    TreeNode *root = new TreeNode(preorder[0]);

    vector<int> lpre(preorder.begin() + 1, preorder.begin() + indexpre);
    vector<int> lpost(postorder.begin(), postorder.begin() + indexpost + 1);

    vector<int> rpre(preorder.begin() + indexpre, preorder.end());
    vector<int> rpost(postorder.begin() + indexpost, postorder.end() - 1);

    root->left = constructFromPrePost(lpre, lpost);
    root->right = constructFromPrePost(rpre, rpost);
    return root;
}

// Hashing
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n1 = preorder.size();
    int n2 = postorder.size();
    int val = preorder[0];
    TreeNode *root = new TreeNode(val);
    unordered_map<int, TreeNode *> m;
    m[val] = root;

    for (int i = 1; i < n1; i++)
    {
        int index = search(preorder[i], postorder);
        for (int j = index + 1; j < n2; j++)
        {
            if (m.find(postorder[j]) != m.end())
            {
                TreeNode *node = new TreeNode(preorder[i]);
                if (!m[postorder[j]]->left)
                    m[postorder[j]]->left = node;
                else
                    m[postorder[j]]->right = node;

                m[preorder[i]] = node;
                break;
            }
        }
    }
    return root;
}