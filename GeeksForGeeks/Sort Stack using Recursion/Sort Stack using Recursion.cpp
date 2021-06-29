#include <bits/stdc++.h>
using namespace std;

void insert(int data, stack<int> &s)
{
    if (s.empty() || data > s.top())
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();
    insert(data, s);

    s.push(temp);
}

void sort(stack<int> &s)
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();

    sort(s);

    insert(temp, s);
}