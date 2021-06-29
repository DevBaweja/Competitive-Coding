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

Node *LCA(Node *root, int t1, int t2)
{
    Node *temp = root;
    int n1 = min(t1, t2);
    int n2 = max(t1, t2);
    while (temp)
    {
        if (n1 <= temp->data && temp->data <= n2)
            return temp;
        else if (temp->data < n1)
            temp = temp->right;
        else if (temp->data > n2)
            temp = temp->left;
    }
}