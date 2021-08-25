#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Iterative

vector<int> verticalSum(Node *root)
{
    if (!root)
        return {};
    if (!root->left && !root->right)
        return {root->data};

    map<int, int> m;
    queue<pair<int, Node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<int, Node *> temp = q.front();
            q.pop();

            m[temp.first] += temp.second->data;

            if (temp.second->left)
                q.push({temp.first - 1, temp.second->left});
            if (temp.second->right)
                q.push({temp.first + 1, temp.second->right});
        }
    }
    vector<int> res;
    for (auto el : m)
        res.push_back(el.second);
    return res;
}

// Recursion

void verticalSumUtil(Node *root, int index, map<int, int> &m)
{
    if (!root)
        return;
    verticalSumUtil(root->left, index - 1, m);
    m[index] += root->data;
    verticalSumUtil(root->right, index + 1, m);
}

vector<int> verticalSum(Node *root)
{
    map<int, int> m;
    verticalSumUtil(root, 0, m);
    vector<int> res;
    for (auto el : m)
        res.push_back(el.second);
    return res;
}

// Double Linked List
// Space O(n)
struct LLNode
{
    int data;
    struct LLNode *prev, *next;
};

LLNode *newLLNode(int data)
{
    LLNode *temp = new LLNode;
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

void verticalSumUtil(Node *root, LLNode *sum)
{
    if (!root)
        return;

    sum->data += root->data;

    if (root->left)
    {
        if (!sum->prev)
        {
            sum->prev = newLLNode(0);
            sum->prev->next = sum;
        }
        verticalSumUtil(root->left, sum->prev);
    }
    if (root->right)
    {
        if (!sum->next)
        {
            sum->next = newLLNode(0);
            sum->next->prev = sum;
        }
        verticalSumUtil(root->right, sum->next);
    }
}

vector<int> verticalSum(Node *root)
{
    LLNode *sum = newLLNode(0);
    verticalSumUtil(root, sum);
    vector<int> res;
    while (sum->prev)
        sum = sum->prev;

    while (sum)
    {
        res.push_back(sum->data);
        sum = sum->next;
    }

    return res;
}