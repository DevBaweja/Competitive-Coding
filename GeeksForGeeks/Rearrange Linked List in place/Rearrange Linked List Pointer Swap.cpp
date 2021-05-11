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

    Node *rearrangePointerSwap(Node *root)
    {
        Node *first = root;
        while (first && first->next)
        {
            Node *last = first;
            while (last->next->next)
                last = last->next;
            Node *next = last->next;
            last->next = NULL;

            Node *rem = first->next;
            first->next = next;

            next->next = rem;
            first = rem;
        }
        return root;
    }
};

int main()
{

    LinkedList ll1;
    // 1->2->3->4
    // 1->4->2->3
    ll1.push(4);
    ll1.push(3);
    ll1.push(2);
    ll1.push(1);

    ll1.head = ll1.rearrangePointerSwap(ll1.head);
    ll1.print();
    cout << "\n";

    LinkedList ll2;
    // 1->2->3->4->5
    // 1->5->2->4->3
    ll2.push(5);
    ll2.push(4);
    ll2.push(3);
    ll2.push(2);
    ll2.push(1);

    ll2.head = ll2.rearrangePointerSwap(ll2.head);
    ll2.print();
    cout << "\n";

    return 0;
}