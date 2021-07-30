#include <bits/stdc++.h>
using namespace std;

// Using First Occuerence
string chooseandswap(string s)
{
    int n = s.size();
    vector<int> v(26, -1);
    for (int i = 0; i < n; i++)
        if (v[s[i] - 'a'] == -1)
            v[s[i] - 'a'] = i;

    int i, j;
    for (i = 0; i < n; i++)
    {
        int k = s[i] - 'a';
        int flag = false;
        for (j = 0; j < k; j++)
        {
            if (v[j] != -1 && v[j] > v[k])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    if (i < n)
    {
        char c1 = s[i];
        char c2 = (char)j + 'a';
        for (int e = 0; e < n; e++)
        {
            if (s[e] == c1)
                s[e] = c2;
            else if (s[e] == c2)
                s[e] = c1;
        }
    }
    return s;
}

// Using Set
string chooseandswap(string a)
{
    int n = a.size();
    set<char> s;
    for (int ch : a)
        s.insert(ch);

    for (int ch1 : a)
    {
        s.erase(ch1);
        if (s.empty())
            break;
        char ch2 = *(s.begin());
        if (ch2 < ch1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == ch1)
                    a[i] = ch2;
                else if (a[i] == ch2)
                    a[i] = ch1;
            }
            break;
        }
    }
    return a;
}