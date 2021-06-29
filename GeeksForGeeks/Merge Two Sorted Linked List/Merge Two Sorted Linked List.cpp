#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/*
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* result = NULL;
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    if(head1->data <= head2->data){
        result = head1;
        result->next = sortedMerge(head1->next, head2);
    }
    else{
        result = head2;
        result->next = sortedMerge(head1, head2->next);
    }
    return result;
}
*/

Node *sortedMerge(Node *a, Node *b)
{
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    while (a && b)
    {
        if (a->data <= b->data)
        {
            tail->next = new Node(a->data);
            a = a->next;
        }
        else
        {
            tail->next = new Node(b->data);
            b = b->next;
        }
        tail = tail->next;
    }

    while (a)
    {
        tail->next = new Node(a->data);
        a = a->next;
        tail = tail->next;
    }
    while (b)
    {
        tail->next = new Node(b->data);
        b = b->next;
        tail = tail->next;
    }
    return dummy->next;
}