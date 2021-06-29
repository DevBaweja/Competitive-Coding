#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
/*
    void heightRecur(Node *root, int level, int *maxHeight){
        if(root==NULL) return;
        heightRecur(root->left, level+1, maxHeight);
        heightRecur(root->right, level+1, maxHeight);
        *maxHeight = max(*maxHeight, level);
    }
    //Function to find the height of a binary tree.
    int height(Node* node){
        int maxHeight = 0;
        heightRecur(node, 1, &maxHeight);
        return maxHeight;
    }
*/
/*
    int height(Node* node){
        if(node == NULL) return 0;
        int lheight = height(node->left);
        int rheight = height(node->right);
        int maxHeight = max(lheight, rheight);
        return maxHeight+1;
    }
*/

int height(Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}