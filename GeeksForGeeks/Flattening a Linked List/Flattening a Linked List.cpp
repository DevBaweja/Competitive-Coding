#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *flatten(Node *root)
{
    Node *cur;
    cur = root;
    while (cur)
    {
        Node *next = cur->next;
        cur->next = cur->bottom;
        cur->bottom = NULL;

        Node *prev = cur->next;
        while (prev && prev->bottom)
        {
            prev->next = prev->bottom;
            prev->bottom = NULL;
            prev = prev->next;
        }
        if (prev)
            prev->next = next;
        cur = next;
    }
    vector<int> v;
    Node *temp;
    temp = root;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end());
    temp = root;
    for (int el : v)
    {
        temp->data = el;
        temp = temp->next;
    }

    cur = root;
    while (cur)
    {
        cur->bottom = cur->next;
        cur->next = NULL;
        cur = cur->bottom;
    }
    return root;
}

void addNode(Node *&temp, int data)
{
    temp->bottom = new Node(data);
    temp = temp->bottom;
}

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
Node *flatten(Node *root)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    Node *r = root;
    while (r)
    {
        pq.push(r);
        r = r->next;
    }

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (!pq.empty())
    {
        Node *el = pq.top();
        pq.pop();
        addNode(temp, el->data);
        if (el->bottom)
            pq.push(el->bottom);
    }

    return dummy->bottom;
}

Node *mergeSorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    Node *res = NULL;
    if (a->data <= b->data)
    {
        res = a;
        res->bottom = mergeSorted(a->bottom, b);
    }
    else
    {
        res = b;
        res->bottom = mergeSorted(a, b->bottom);
    }
    res->next = NULL;
    return res;
}

Node *flatten(Node *root)
{
    if (!root || !root->next)
        return root;

    root->next = flatten(root->next);
    root = mergeSorted(root, root->next);
    return root;
}
