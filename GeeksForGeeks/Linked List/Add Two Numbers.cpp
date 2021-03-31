#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

Node *reverse(Node *head)
{
    Node *prev = NULL, *next = NULL, *current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *addTwoNumbers(Node *first, Node *second)
{
    Node *head = NULL, *temp = NULL;
    first = reverse(first);
    second = reverse(second);

    Node *temp1 = first, *temp2 = second;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        int rem = sum % 10;
        carry = sum / 10;
        if (head == NULL)
        {
            head = new Node(rem);
            temp = head;
        }
        else
        {
            temp->next = new Node(rem);
            temp = temp->next;
        }
    }

    if (carry)
        temp->next = new Node(carry);

    return reverse(head);
}
// Time - O(n+m) where m and n are number of nodes in first and second lists respectively.
// Space - O(n+m)

int main()
{
    LinkedList l1;
    l1.push(5);
    l1.push(6);
    l1.push(3);
    l1.print();
    LinkedList l2;
    l2.push(8);
    l2.push(4);
    l2.push(2);
    l2.print();

    LinkedList l3;
    l3.head = addTwoNumbers(l1.head, l2.head);
    l3.print();
    return 0;
}