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

    void deleteNM(int m, int n)
    {
        Node *temp = head;
        while (temp)
        {
            int i = m - 1, j = n + 1;
            while (temp && i--)
                temp = temp->next;
            if (!temp)
                return;

            Node *post = temp;
            while (post && j--)
                post = post->next;

            temp->next = post;
            temp = post;
        }
    }
};

int main()
{

    LinkedList ll;
    // 9 1 3 5 9 4 10 1
    int m = 2, n = 1;
    ll.push(1);
    ll.push(10);
    ll.push(4);
    ll.push(9);
    ll.push(5);
    ll.push(3);
    ll.push(1);
    ll.push(9);

    ll.deleteNM(m, n);

    ll.print();
    return 0;
}