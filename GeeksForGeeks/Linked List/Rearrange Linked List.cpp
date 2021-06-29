#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *inPlace(Node *root)
{
    Node *first = root;
    while (first && first->next)
    {
        Node *last = first;
        while (last->next->next)
            last = last->next;
        Node *next = last->next;
        last->next = NULL;

        Node *rem = first->next;
        first->next = next;

        next->next = rem;
        first = rem;
    }
    return root;
}

Node *inPlace(Node *root)
{
    Node *temp;
    temp = root;
    vector<int> A;
    while (temp)
    {
        A.push_back(temp->data);
        temp = temp->next;
    }

    int n = A.size();
    temp = root;
    int index = 0;

    while (temp && temp->next)
    {
        temp->data = A[index];
        temp = temp->next;

        temp->data = A[n - index - 1];
        temp = temp->next;
        index++;
    }

    if (temp)
        temp->data = A[index];

    return root;
}