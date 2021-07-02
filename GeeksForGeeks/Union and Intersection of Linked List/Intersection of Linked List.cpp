#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *addNode(Node *&head, int data)
{
    if (!head)
        return new Node(data);
    head->next = new Node(data);
    head = head->next;
}

Node *findIntersection(Node *head1, Node *head2)
{

    unordered_set<int> m;
    while (head2)
    {
        m.insert(head2->data);
        head2 = head2->next;
    }
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (head1)
    {
        if (m.find(head1->data) != m.end())
            addNode(temp, head1->data);
        head1 = head1->next;
    }
    return dummy->next;
}