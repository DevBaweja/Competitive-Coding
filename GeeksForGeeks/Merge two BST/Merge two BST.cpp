#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void traverse(Node *root, vector<int> &r)
{
    if (!root)
        return;
    traverse(root->left, r);
    r.push_back(root->data);
    traverse(root->right, r);
}

vector<int> combine(vector<int> r1, vector<int> r2)
{
    int n1 = r1.size(), n2 = r2.size();
    int n = n1 + n2;
    vector<int> r(n);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (r1[i] <= r2[j])
            r[k++] = r1[i++];
        else
            r[k++] = r2[j++];
    }
    while (i < n1)
        r[k++] = r1[i++];
    while (j < n2)
        r[k++] = r2[j++];
    return r;
}

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> r1, r2;
    traverse(root1, r1);
    traverse(root2, r2);
    return combine(r1, r2);
}