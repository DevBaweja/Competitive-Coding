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

    Node *reverse(Node *head)
    {
        Node *current = head, *prev = NULL, *next = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    Node *addOne(Node *head)
    {
        head = reverse(head);
        Node *temp = head;
        int carry = 1;
        while (temp && carry)
        {
            int res = temp->data + carry;
            int rem = res % 10;
            carry = res / 10;
            temp->data = rem;
            temp = temp->next;
        }
        if (carry)
        {
            temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = new Node(carry);
        }

        return reverse(head);
    }

    int addWithCarry(Node *head)
    {
        if (head == NULL)
            return 1;
        int res = head->data + addWithCarry(head->next);
        head->data = res % 10;
        return res / 10;
    }

    Node *addOneRecursive(Node *head)
    {
        int carry = addWithCarry(head);
        if (carry)
        {
            Node *temp = new Node(carry);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};

int main()
{

    LinkedList ll;
    ll.push(7);
    ll.push(5);
    ll.push(4);

    ll.head = ll.addOne(ll.head);
    ll.head = ll.addOneRecursive(ll.head);

    ll.print();
    return 0;
}