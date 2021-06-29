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

Node *insert(Node *root, int key)
{
    Node *temp = root;
    while (temp)
    {
        if (temp->data == key)
            return root;
        if (temp->data > key)
        {
            if (temp->left)
                temp = temp->left;
            else
            {
                temp->left = new Node(key);
                return root;
            }
        }
        else
        {
            if (temp->right)
                temp = temp->right;
            else
            {
                temp->right = new Node(key);
                return root;
            }
        }
    }
    return root;
}