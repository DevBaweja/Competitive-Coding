#include <bits/stdc++.h>
using namespace std;

// Stack
int minAddToMakeValid(string s)
{
    int count = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')' && !st.empty())
            st.pop();
        else
            count++;
    }
    if (!st.empty())
        count += st.size();
    return count;
}

// Without Stack
int minAddToMakeValid(string s)
{
    int count = 0;
    int st = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st++;
        else if (s[i] == ')' && st != 0)
            st--;
        else
            count++;
    }
    if (st != 0)
        count += st;
    return count;
}