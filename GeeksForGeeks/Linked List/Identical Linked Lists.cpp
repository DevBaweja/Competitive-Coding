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

bool isIdentical(Node *head1, Node *head2)
{
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 || temp2)
        return false;
    return true;
}

bool isIdenticalRecur(Node *head1, Node *head2)
{
    if (!head1 && !head2)
        return true;
    if (!head1 || !head2)
        return false;

    if (head1->data != head2->data)
        return false;

    return isIdenticalRecur(head1->next, head2->next);
}

bool isIdenticalRecursive(Node *head1, Node *head2)
{
    if (!head1 && !head2)
        return true;

    if (head1 && head2)
        return (head1->data == head2->data) && isIdenticalRecursive(head1->next, head2->next);

    return false;
}

int main()
{

    LinkedList ll1;
    ll1.push(1);
    ll1.push(2);
    ll1.push(3);

    LinkedList ll2;
    ll2.push(1);
    ll2.push(2);
    ll2.push(3);

    cout << isIdentical(ll1.head, ll2.head) << endl;
    return 0;
}