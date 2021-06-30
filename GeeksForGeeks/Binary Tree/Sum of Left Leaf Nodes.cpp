#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void leftLeafSumUtil(Node *root, int &sum)
{
    if (!root)
        return;

    if (root->left)
        if (!root->left->left && !root->left->right)
            sum += root->left->data;

    leftLeafSumUtil(root->left, sum);
    leftLeafSumUtil(root->right, sum);
}

int leftLeafSum(Node *root)
{
    int sum = 0;
    leftLeafSumUtil(root, sum);
    return sum;
}

int leftLeafSum(Node *root)
{
    int sum = 0;
    if (!root)
        return sum;
    queue<pair<Node *, bool>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            if (!temp.first->left && !temp.first->right && temp.second)
                sum += temp.first->data;
            if (temp.first->left)
                q.push({temp.first->left, 1});
            if (temp.first->right)
                q.push({temp.first->right, 0});
        }
    }
    return sum;
}