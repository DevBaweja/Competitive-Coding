#include <bits/stdc++.h>
using namespace std;

bool isEqual(char a, char b)
{
    int aa = a - '0';
    int bb = b - '0';
    int diff = 97 - 65;
    return abs(aa - bb) == diff;
}
string makeGood(string s)
{
    stack<char> st;
    for (int ch : s)
    {
        if (!st.empty() && isEqual(ch, st.top()))
            st.pop();
        else
            st.push(ch);
    }
    string r = "";
    while (!st.empty())
    {
        r = st.top() + r;
        st.pop();
    }
    return r;
}