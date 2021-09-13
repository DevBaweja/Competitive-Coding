#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k)
{
    vector<int> s;
    s.push_back(0);
    for (int i = 1; i < n; i++)
    {
        vector<int> t;
        for (int el : s)
        {
            if (el)
            {
                t.push_back(1);
                t.push_back(0);
            }
            else
            {
                t.push_back(0);
                t.push_back(1);
            }
        }
        s = t;
    }
    return s[k - 1];
}

// Recursion
// Half remain same, Half become opposite
int kthGrammar(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;
    int size = pow(2, n - 1) / 2;
    if (k <= size)
        return kthGrammar(n - 1, k);
    return !kthGrammar(n - 1, k - size);
}