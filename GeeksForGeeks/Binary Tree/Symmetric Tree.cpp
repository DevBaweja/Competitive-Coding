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

/*
bool isSymmetricUtil(Node* left, Node* right){
    if(!left && !right) return true;
    if((left && !right) || (!left && right)) return false;
    
    return (left->data == right->data) && 
    isSymmetricUtil(left->left, right->right) &&
    isSymmetricUtil(left->right, right->left);
}

bool isSymmetric(Node* root)
{
	return isSymmetricUtil(root, root);
}
*/

// Iterative
bool isSymmetric(Node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;

    queue<Node *> q;

    q.push(root);
    q.push(root);
    // At each level palindrome
    while (!q.empty())
    {
        Node *left = q.front();
        q.pop();
        Node *right = q.front();
        q.pop();

        if (left->data != right->data)
            return false;

        if (left->left && right->right)
        {
            q.push(left->left);
            q.push(right->right);
        }
        else if (left->left || right->right)
            return false;

        if (left->right && right->left)
        {
            q.push(left->right);
            q.push(right->left);
        }
        else if (left->right || right->left)
            return false;
    }
    return true;
}