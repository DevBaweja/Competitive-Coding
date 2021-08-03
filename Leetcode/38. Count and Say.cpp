#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string countAndSay(int n)
{
    string s = "1";
    for (int i = 1; i < n; i++)
    {
        string t = "";
        s += '$';
        int m = s.size();
        int c = 1;
        for (int j = 1; j < m; j++)
        {
            if (s[j - 1] == s[j])
                c++;
            else
            {
                t += to_string(c);
                t += s[j - 1];
                c = 1;
            }
        }
        s = t;
    }
    return s;
}