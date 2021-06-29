#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s)
{
    stack<int> c;
    for (int i = 0; i < s.length(); i++)
    {
        char cur = s[i];
        if (cur == '*' || cur == '/' || cur == '+' || cur == '-')
        {
            int a = c.top();
            c.pop();
            int b = c.top();
            c.pop();
            switch (cur)
            {
            case '*':
                c.push(b * a);
                break;
            case '/':
                c.push(b / a);
                break;
            case '+':
                c.push(b + a);
                break;
            case '-':
                c.push(b - a);
                break;
            }
        }
        else
            c.push(cur - '0');
    }
    return c.top();
}