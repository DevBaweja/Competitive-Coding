#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
    vector<string> res(n);
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        string s = "";
        while (t)
        {
            s = to_string(t & 1) + s;
            t = t >> 1;
        }
        res[i - 1] = s;
    }
    return res;
}

vector<string> generate(int n)
{
    queue<string> q;
    q.push("1");
    vector<string> res(n);
    for (int i = 1; i <= n; i++)
    {
        string t = q.front();
        q.pop();
        res[i - 1] = t;
        q.push(t + "0");
        q.push(t + "1");
    }
    return res;
}
