#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List
class Node
{
public:
    int data;
    Node *prev, *next;
    Node()
    {
        data = -1;
        prev = next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};

class MyCircularDeque
{
public:
    int size;
    int cap;
    Node *front, *rear;
    MyCircularDeque(int cap)
    {
        size = 0;
        this->cap = cap;
        front = new Node();
        rear = new Node();
        front->next = rear;
        rear->prev = front;
    }

    bool insertFront(int value)
    {
        if (size == cap)
            return false;
        Node *temp = new Node(value);
        Node *next = front->next;
        front->next = temp;
        temp->prev = front;
        next->prev = temp;
        temp->next = next;
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == cap)
            return false;
        Node *temp = new Node(value);
        Node *prev = rear->prev;
        rear->prev = temp;
        temp->next = rear;
        prev->next = temp;
        temp->prev = prev;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (!size)
            return false;
        Node *temp = front->next->next;
        front->next = front->next->next;
        temp->prev = temp->prev->prev;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (!size)
            return false;
        Node *temp = rear->prev->prev;
        rear->prev = rear->prev->prev;
        temp->next = temp->next->next;
        size--;
        return true;
    }

    int getFront()
    {
        return front->next->data;
    }

    int getRear()
    {
        return rear->prev->data;
    }

    bool isEmpty()
    {
        return (!size);
    }

    bool isFull()
    {
        return (size == cap);
    }
};

// TODO Ring Buffer