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
void Traversal(Node *root, int height, int *maxHeight, vector<int> &res){
    if(!root) return;
    if(height > *maxHeight){
        res.push_back(root->data);
        *maxHeight = height;
    }
    Traversal(root->left, height+1, maxHeight, res);
    Traversal(root->right, height+1, maxHeight, res);
}
vector<int> leftView(Node *root)
{
    vector<int> res;
    int maxHeight = 0;
    Traversal(root, 1, &maxHeight, res);
    return res; 
}
*/

vector<int> leftView(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (!i)
                res.push_back(temp->data);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
}
