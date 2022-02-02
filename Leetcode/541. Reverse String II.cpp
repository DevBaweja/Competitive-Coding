#include <bits/stdc++.h>
using namespace std;

string reverseStr(string s, int k)
{
    int n = s.size();
    bool flag = true;
    int count = 0;
    stack<char> st;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        char el = s[i];
        if (flag)
        {
            st.push(el);
            count++;
            flag = !(count == k);
            if (count == k)
                while (!st.empty())
                {
                    res += st.top();
                    st.pop();
                }
        }
        else
        {

            res += el;
            count--;
            flag = !count;
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}