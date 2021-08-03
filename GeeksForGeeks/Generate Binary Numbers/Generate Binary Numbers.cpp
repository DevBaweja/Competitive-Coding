#include <bits/stdc++.h>
#include <string>
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