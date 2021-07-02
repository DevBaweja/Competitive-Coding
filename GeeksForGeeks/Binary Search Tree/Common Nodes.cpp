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

// Time- O(n+m) Space- O(n+m) Using map
/*
    void Traverse(Node* root, map<int,int> &m){
        if(!root) return;
        Traverse(root->left, m);
        m[root->data]++;
        Traverse(root->right, m);
    }
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> res;
        map<int,int> m1, m2;
        Traverse(root1, m1);
        Traverse(root2, m2);
        
        for(auto itr: m1)
            if(m2[itr.first]) res.push_back(itr.first);
        return res;
    }
*/

/*
    // Time- O(n+m) Space- O(n+m) Using vector
    void Traverse(Node* root, vector<int> &v){
        if(!root) return;
        Traverse(root->left, v);
        v.push_back(root->data);
        Traverse(root->right, v);
    }
    vector<int> Intersection(vector<int> v1, vector<int> v2){
        int i=0, j=0;
        vector<int> res;
        while(i<v1.size() && j<v2.size()){
            if(v1[i] < v2[j])
                i++;
            else if(v1[i] > v2[j])
                j++;
            else if(v1[i] == v2[j])
            {
                res.push_back(v1[i]);
                i++; j++;
            }
        }
        return res;
    }
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> v1, v2;
        Traverse(root1, v1);
        Traverse(root2, v2);
        
        return Intersection(v1,v2);
    }
*/

// Time- O(n+m) Space- O(h1+h2) Iterative Inorder
vector<int> findCommon(Node *root1, Node *root2)
{
    stack<Node *> s1, s2;
    vector<int> res;
    while (1)
    {
        if (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        else if (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        else if (!s1.empty() && !s2.empty())
        {
            root1 = s1.top();
            root2 = s2.top();
            if (root1->data == root2->data)
            {
                res.push_back(root1->data);
                s1.pop();
                s2.pop();
                root1 = root1->right;
                root2 = root2->right;
            }
            else if (root1->data < root2->data)
            {
                s1.pop();
                root1 = root1->right;
                root2 = NULL;
            }
            else if (root1->data > root2->data)
            {
                s2.pop();
                root2 = root2->right;
                root1 = NULL;
            }
        }
        else
            break;
    }
    return res;
}