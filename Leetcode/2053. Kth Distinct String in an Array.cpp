#include <bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string> &v, int k)
{
    int c = 0;
    for (string s : v)
    {
        if (count(v.begin(), v.end(), s) == 1)
        {
            c++;
            if (c == k)
                return s;
        }
    }
    return "";
}
