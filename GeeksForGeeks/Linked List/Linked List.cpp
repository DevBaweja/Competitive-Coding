#include <iostream>
using namespace std;

// class and struct

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
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        struct Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{

    struct LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);

    ll.print();
    return 0;
}