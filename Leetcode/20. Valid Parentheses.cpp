#include <bits/stdc++.h>
using namespace std;

// Stack
bool isValid(string x)
{
    stack<char> s;
    for (char el : x)
    {
        if (el == '{' or el == '(' or el == '[')
        {
            s.push(el);
            continue;
        }

        if (s.empty())
            return false;
        char y = s.top();
        s.pop();
        switch (el)
        {
        case '}':
        {
            if (y == '(' or y == '[')
                return false;
            break;
        }
        case ')':
        {
            if (y == '{' or y == '[')
                return false;
            break;
        }
        case ']':
        {
            if (y == '(' or y == '{')
                return false;
            break;
        }
        }
    }

    if (!s.empty())
        return false;
    return true;
}