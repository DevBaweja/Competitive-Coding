#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> s;
    stack<int> ss;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        if (ss.empty() || val <= ss.top())
            ss.push(val);
    }

    void pop()
    {
        if (s.top() == ss.top())
            ss.pop();
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return ss.top();
    }
};