#include <bits/stdc++.h>
using namespace std;

void matchPairs(char nuts[], char bolts[], int n)
{
    unordered_map<char, char> m;
    for (int i = 0; i < n; i++)
        m[nuts[i]] = i;
    for (int i = 0; i < n; i++)
        if (m.find(bolts[i]) != m.end())
            nuts[i] = bolts[i];
}