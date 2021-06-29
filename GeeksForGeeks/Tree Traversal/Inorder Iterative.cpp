#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/*
    vector<int> inOrder(Node* root)
    {
        vector<int> res;
        Node* cur = root;
        stack<Node*> s;
        while(!s.empty() || cur){
            while(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                Node* temp = s.top();
                s.pop();
                res.push_back(temp->data);
                cur = temp->right;
            }
        }
        return res;
    }
    */
// Morris Traversal
Node *findPred(Node *cur)
{
    Node *temp = cur;
    temp = temp->left;
    while (temp->right && temp->right != cur)
    {
        temp = temp->right;
    }
    return temp;
}

vector<int> inOrder(Node *root)
{
    vector<int> res;
    Node *cur = root;
    while (cur)
    {
        if (!cur->left)
        {
            res.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node *p = findPred(cur);
            if (!p->right)
            {
                p->right = cur;
                cur = cur->left;
            }
            else
            {
                p->right = NULL;
                res.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return res;
}