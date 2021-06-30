#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void getInOrder(Node *root, vector<int> &res)
{
    if (!root)
        return;
    getInOrder(root->left, res);
    res.push_back(root->data);
    getInOrder(root->right, res);
}
void assignInOrder(Node *root, vector<int> res, int *index)
{
    if (!root)
        return;
    assignInOrder(root->left, res, index);
    root->data = res[(*index)++];
    assignInOrder(root->right, res, index);
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> res;
    getInOrder(root, res);
    sort(res.begin(), res.end());
    int index = 0;
    assignInOrder(root, res, &index);
    return root;
}