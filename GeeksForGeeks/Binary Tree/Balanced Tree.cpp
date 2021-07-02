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
void height(Node *root, int level, int *maxHeight){
    if(root==NULL) return;
    height(root->left, level+1, maxHeight);
    height(root->right, level+1, maxHeight);
    *maxHeight = max(*maxHeight, level);
}

bool isBalanced(Node *root)
{
    if(root == NULL) return 1;
    int lheight = 0;
    height(root->left, 1, &lheight);
    int rheight = 0;
    height(root->right, 1, &rheight);
    // cout << lheight << " " << rheight << " ";
    int diff = abs(lheight - rheight);
    if(diff > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
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

bool isBalanced(Node *root)
{
    if (root == NULL)
        return 1;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

/*
bool isBalancedRecur(Node* root, int *height){
    if(root == NULL){
        *height = 0;
        return 1;
    }
    int lh = 0, rh = 0;
    int l = isBalancedRecur(root->left, &lh);
    int r = isBalancedRecur(root->right, &rh);
    *height = max(lh+1, rh+1);
    
    return abs(lh-rh) <= 1 && l && r; 
}

bool isBalanced(Node* root){
    int height = 0;
    return isBalancedRecur(root,&height);
}
*/