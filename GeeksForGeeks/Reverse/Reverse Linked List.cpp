#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    struct Node *head;
    LinkedList() { head = NULL; }

    void push(int data)
    {
        struct Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverseIterative()
    {
        struct Node *cur = head;
        struct Node *prev = NULL, *next = NULL;

        while (cur != NULL)
        {
            next = cur->next;

            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    // Time - O(n)
    // Space - O(1)
    Node *reverseRecursive(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // Reversing rest
        Node *rest = reverseRecursive(head->next);
        // Swaping
        head->next->next = head;

        head->next = NULL;
        return rest;
    }
};

int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.print();
    // ll.reverseIterative();
    ll.head = ll.reverseRecursive(ll.head);
    cout << endl;
    ll.print();

    return 0;
}