#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();
    if (n <= k)
        return "0";
    string res = num;
    while (k--)
    {
        for (int i = 0; i < num.size(); i++)
        {
            string temp = num;
            temp.erase(temp.begin() + i);
            res = min(res, temp);
        }
        num = res;
    }
    int count = 0;
    for (int i = 0; i < res.size() && res[i] == '0'; i++)
        count++;

    while (count)
    {
        res.erase(res.begin() + count - 1);
        count--;
    }

    return res != "" ? res : "0";
}

string removeKdigits(string num, int k)
{
    int n = num.size();
    if (n <= k)
        return "0";
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() > num[i] && k)
        {
            s.pop();
            k--;
        }
        if (!s.empty() || num[i] != '0')
        {
            s.push(num[i]);
        }
    }

    while (!s.empty() && k)
    {
        s.pop();
        k--;
    }

    if (s.empty())
        return "0";

    string res = "";
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}