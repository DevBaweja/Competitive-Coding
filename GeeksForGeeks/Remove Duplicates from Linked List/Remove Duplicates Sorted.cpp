#include <iostream>
#include <set>
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

    Node *removeDuplicatesSorted(Node *head)
    {
        if (!head)
            return head;
        Node *root = head;
        while (root->next)
        {
            if (root->data == root->next->data)
                root->next = root->next->next;
            else
                root = root->next;
        }
        return head;
    }
    void removeDuplicatesSortedRecur(Node *head)
    {
        if (!head)
            return;

        if (head->next)
        {
            if (head->data == head->next->data)
            {
                head->next = head->next->next;
                removeDuplicatesSortedRecur(head);
            }
            removeDuplicatesSortedRecur(head->next);
        }
    }
};

int main()
{

    LinkedList ll1;
    ll1.push(60);
    ll1.push(43);
    ll1.push(43);
    ll1.push(21);
    ll1.push(11);
    ll1.push(11);
    ll1.push(11);

    ll1.head = ll1.removeDuplicatesSorted(ll1.head);
    ll1.print();
    cout << "\n";

    LinkedList ll2;
    ll2.push(20);
    ll2.push(13);
    ll2.push(13);
    ll2.push(11);
    ll2.push(11);
    ll2.push(11);

    ll2.removeDuplicatesSortedRecur(ll2.head);
    ll2.print();
    cout << "\n";

    return 0;
}