#include <bits/stdc++.h>
using namespace std;

vector<int> search(string pat, string txt)
{
    vector<int> res;
    int n = pat.size();
    vector<int> prefix(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && pat[i] != pat[j])
            j = prefix[j - 1];
        if (pat[i] == pat[j])
            j++;
        prefix[i] = j;
    }

    int m = txt.size();
    int i = 0, j = 0;
    while (i < m)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
        if (j == n)
        {
            res.push_back(i - n + 1);
            j = prefix[j - 1];
        }
    }

    return res;
}