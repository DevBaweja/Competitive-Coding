#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/*
    void getMaxWidthUtil(Node* root, int level, map<int,int> &m){
        if(root==NULL) return;
        m[level]++;
        getMaxWidthUtil(root->left,level+1,m);
        getMaxWidthUtil(root->right,level+1,m); 
    }
    int getMaxWidth(Node* root)
    {
        map<int,int> m;
        getMaxWidthUtil(root, 1, m);
        
        int res = 1;
        for(auto itr = m.begin(); itr!=m.end(); ++itr)
            res = max(res,itr->second);
        
        return res;
    }
*/

int getMaxWidth(Node *root)
{
    int res = 1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        res = max(res, count);
        while (count--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
}