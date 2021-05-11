#include <bits/stdc++.h>
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

    bool detectLoops(Node *head)
    {
        Node *first = head, *last = head;
        int curr_length = 0, prev_length = -1;
        while (curr_length > prev_length && last)
        {
            prev_length = curr_length;
            curr_length = distance(first, last);
            last = last->next;
        }
        // As moment it last enters cycle, distance will decrease
        if (last)
            return true;
        return false;
    }
    // Time - O(n*n)
    // Space - O(1)
};

int main()
{

    LinkedList ll;
    // 1->2->3->4->1
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.head->next->next->next = ll.head;

    cout << ll.detectLoops(ll.head);

    return 0;
}