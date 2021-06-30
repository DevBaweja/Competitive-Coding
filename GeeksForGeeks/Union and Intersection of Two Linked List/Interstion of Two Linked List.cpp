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

Node *addNode(Node *head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return head;
    }

    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *temp1 = head1, *temp2 = head2;

    Node *head = NULL;

    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
            temp1 = temp1->next;
        else if (temp1->data > temp2->data)
            temp2 = temp2->next;
        else
        {
            head = addNode(head, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return reverse(head);
}