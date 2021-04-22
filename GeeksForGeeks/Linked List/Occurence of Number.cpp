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

    int countIterative(int key)
    {
        Node *temp = head;
        int c = 0;
        while (temp)
        {
            if (temp->data == key)
                c++;
            temp = temp->next;
        }
        return c;
    }

    int countRecursive(Node *head, int key)
    {
        if (head == NULL)
            return 0;
        if (head->data == key)
            return 1 + countRecursive(head->next, key);
        return countRecursive(head->next, key);
    }
};

int main()
{

    LinkedList ll;
    // 1->2->1->2->1->3->1
    ll.push(1);
    ll.push(2);
    ll.push(1);
    ll.push(2);
    ll.push(1);
    ll.push(3);
    ll.push(1);

    cout << ll.countIterative(1) << endl;
    cout << ll.countRecursive(ll.head, 1) << endl;

    return 0;
}