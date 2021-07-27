#include <bits/stdc++.h>
using namespace std;

// Using Stack
string reverseParentheses(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            string temp = "";
            while (st.top() != '(')
            {
                temp += st.top();
                st.pop();
            }
            st.pop();
            for (int j = 0; j < temp.length(); j++)
                st.push(temp[j]);
        }
        else
            st.push(s[i]);
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Unique Traversal
string reverseParentheses(string s)
{
    int n = s.length();
    stack<int> st;
    vector<int> pair(n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            int j = st.top();
            st.pop();
            pair[i] = j;
            pair[j] = i;
        }
    }

    string ans = "";
    for (int i = 0, d = 1; i < n; i += d)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            i = pair[i];
            d = -d;
        }
        else
            ans += s[i];
    }
    return ans;
}