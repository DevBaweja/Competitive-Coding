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
// Time- O(n*log(n))
// Space- O(n*log(n))
/*
    void findMiddle(Node* head, Node* &l1, Node* &l2){
        Node *f=head->next, *s=head;
        while(f){
            f = f->next;
            if(f){
                f = f->next;
                s = s->next;
            }
        }
        
        l1 = head;
        l2 = s->next;
        s->next = NULL;
    }
    
    Node* SortedMerge(Node* a, Node* b)
    {
        Node* result = NULL;
        if (!a)
            return b;
        if (!b)
            return a;
        if (a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return result;
    }
    
    void printList(Node* temp){
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        Node *l1=NULL,*l2=NULL;
        findMiddle(head, l1, l2);
        // printList(l1);
        // printList(l2);
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);
        head = SortedMerge(l1, l2);
        return head;
    }
*/

void findMiddle(Node *head, Node *&l1, Node *&l2)
{
    Node *f = head->next, *s = head;
    while (f)
    {
        f = f->next;
        if (f)
        {
            f = f->next;
            s = s->next;
        }
    }

    l1 = head;
    l2 = s->next;
    s->next = NULL;
}

Node *SortedMerge(Node *a, Node *b)
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

void printList(Node *temp)
{
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *l1 = NULL, *l2 = NULL;
    findMiddle(head, l1, l2);
    // printList(l1);
    // printList(l2);
    l1 = mergeSort(l1);
    l2 = mergeSort(l2);
    head = SortedMerge(l1, l2);
    return head;
}