#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, stack<int> &t)
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    insert(s, t);
    t.push(temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    stack<int> t;
    insert(s, t);
    while (!t.empty())
    {
        cout << t.top();
        t.pop();
    }
    return 0;
}