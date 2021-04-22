#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

Node *merge(Node *h1, Node *h2)
{
    Node *res = NULL;
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    if (h1->data <= h2->data)
    {
        res = h1;
        res->next = merge(h1->next, h2);
    }
    else
    {
        res = h2;
        res->next = merge(h1, h2->next);
    }
    return res;
}

int main()
{

    LinkedList ll1;
    ll1.push(5);
    ll1.push(3);
    ll1.push(1);

    LinkedList ll2;
    ll2.push(6);
    ll2.push(4);
    ll2.push(2);

    LinkedList ll3;
    ll3.head = merge(ll1.head, ll2.head);
    ll3.print();
    return 0;
}