#include <bits/stdc++.h>
using namespace std;

int clumsy(int n)
{
    if (n == 1 || n == 2)
        return n;
    if (n == 3)
        return 6;
    int count = 0;
    stack<int> si, so;
    si.push(n);
    while (--n)
    {
        if (count == 0)
        {
            int el = si.top();
            si.pop();
            si.push(el * n);
        }
        if (count == 1)
        {
            int el = si.top();
            si.pop();
            si.push(el / n);
        }
        if (count == 2)
        {
            si.push(n);
            so.push(0);
        }
        if (count == 3)
        {
            si.push(n);
            so.push(1);
        }
        count = (count + 1) % 4;
    }

    int el = si.top();
    si.pop();
    int op = so.top();
    so.pop();
    if (op)
        el = -el;

    while (!so.empty())
    {
        int op = so.top();
        so.pop();
        cout << op << " ";
        cout << si.top() << " ";
        if (!op)
            el += si.top();
        else
            el -= si.top();
        si.pop();
    }

    return el + si.top();
}