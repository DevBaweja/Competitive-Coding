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
vector<int> findSpiral(Node *root)
{
    if (!root)
        return {};
    vector<int> res;
    stack<Node *> s1, s2;
    s2.push(root);
    bool ltr = false;
    while (!s1.empty() || !s2.empty())
    {
        int count;
        if (ltr)
            count = s1.size();
        else
            count = s2.size();

        while (count--)
        {
            Node *temp;
            if (ltr)
            {
                temp = s1.top();
                s1.pop();
            }
            else
            {
                temp = s2.top();
                s2.pop();
            }

            res.push_back(temp->data);
            if (ltr)
            {
                if (temp->left)
                    s2.push(temp->left);
                if (temp->right)
                    s2.push(temp->right);
            }
            else
            {
                if (temp->right)
                    s1.push(temp->right);
                if (temp->left)
                    s1.push(temp->left);
            }
        }
        ltr = !ltr;
    }

    return res;
}