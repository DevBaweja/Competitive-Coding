#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/*
vector<int> preOrder(Node* root)
{
    Node* cur = root;
    stack<Node*>s;
    vector<int> res;
    while(cur || !s.empty()){
        while(cur){
            res.push_back(cur->data);
            s.push(cur);
            cur = cur->left;
        }
        if(!s.empty()){
            Node* temp = s.top();
            s.pop();
            cur = temp->right;
        }
    }
    return res;
}
*/

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

vector<int> preOrder(Node *root)
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
                res.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                p->right = NULL;
                cur = cur->right;
            }
        }
    }
    return res;
}