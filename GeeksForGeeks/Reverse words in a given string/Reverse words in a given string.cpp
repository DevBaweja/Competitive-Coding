#include <bits/stdc++.h>
using namespace std;

// Using Stack
string reverseWords(string st)
{
    stack<char> s;
    for (char el : st)
    {
        if (el == '.')
        {
            string temp = "";
            while (!s.empty() && s.top() != '.')
            {
                temp += s.top();
                s.pop();
            }
            for (char ch : temp)
                s.push(ch);
        }
        s.push(el);
    }
    string temp = "";
    while (!s.empty() && s.top() != '.')
    {
        temp += s.top();
        s.pop();
    }
    for (char ch : temp)
        s.push(ch);

    string res = "";
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    return res;
}

// Using Vector
string reverseWords(string st)
{
    vector<string> v;
    string temp = "";
    for (char el : st)
    {
        if (el != '.')
            temp += el;
        else
        {
            v.push_back(temp);
            temp = "";
        }
    }
    v.push_back(temp);

    string res = "";
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        res += v[i];
        if (i != 0)
            res += '.';
    }
    return res;
}