#include <bits/stdc++.h>
using namespace std;

// Exponential

vector<string> AllPossibleStrings(string s)
{
    int n = s.size();
    int p = pow(2, n);
    vector<string> res;
    for (int counter = 1; counter < p; counter++)
    {
        string k = "";
        for (int i = 0; i < n; i++)
        {
            if (counter & (1 << i))
                k += s[i];
        }
        res.push_back(k);
    }
    return res;
}