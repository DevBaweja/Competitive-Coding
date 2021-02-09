#include <iostream>
using namespace std;

class Stack
{
    int top;
    int capacity;
    int *A;

public:
    Stack(int c)
    {
        top = -1;
        capacity = c;
        A = new int[capacity];
    };
    bool isEmpty() { return top == -1; };
    bool isFull() { return top == capacity - 1; };
    void push(int el)
    {
        if (isFull())
            return;
        A[++top] = el;
    }
    void pop()
    {
        if (isEmpty())
            return;
        top--;
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return A[top];
    }

    void display()
    {
        if (isEmpty())
            return;
        int temp = top;
        while (temp >= 0)
        {
            cout << A[temp] << " ";
            temp--;
        }
    }
};

int main()
{
    class Stack s(10);
    s.push(10);
    s.push(20);
    s.isFull();
    s.push(30);
    s.peek();
    s.isEmpty();
    s.pop();
    s.display();

    return 0;
}