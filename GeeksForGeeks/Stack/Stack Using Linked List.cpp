#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = new Node();
    };
    bool isEmpty() { return top == NULL; };
    void push(int el)
    {
        Node *temp = new Node();
        temp->data = el;
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (isEmpty())
            return;
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return top->data;
    }

    void display()
    {
        if (isEmpty())
            return;
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.isEmpty();
    s.pop();
    s.display();

    return 0;
}