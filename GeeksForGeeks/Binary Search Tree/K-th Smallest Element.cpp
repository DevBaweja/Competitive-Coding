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

// Time- O(h+k)
// Space- O(h)
void Traverse(Node *root, int &count, int &res, int k)
{
    if (!root || count >= k)
        return;
    Traverse(root->left, count, res, k);
    count++;
    if (count == k)
        res = root->data;
    Traverse(root->right, count, res, k);
}

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int k)
{
    int res = -1;
    int count = 0;
    Traverse(root, count, res, k);
    return res;
}
// Augmented - Store left count of node while makiing tree
// And search accordingly to left or right subtree
// Time- O(h) Space- O(h)