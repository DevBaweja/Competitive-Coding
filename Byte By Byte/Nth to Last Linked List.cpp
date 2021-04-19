#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct LinkedList
{
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

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
    /*
    void lastValue(int index)
    {
        int count = 0;
        Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }

        int findex = count - index;

        temp = head;
        while (findex--)
        {
            temp = temp->next;
        }
        cout << temp->data;
    }
    */

    void lastValue(int index)
    {
        Node *prev = head;
        Node *curr = head;

        while (index--)
            curr = curr->next;
        while (curr->next != NULL)
        {
            curr = curr->next;
            prev = prev->next;
        }
        cout << prev->data;
    }
};
// Time - O(n)

int main()
{
    LinkedList ll;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ll.push(temp);
    }
    ll.print();
    cout << "\n";
    ll.lastValue(x);
    return 0;
}
