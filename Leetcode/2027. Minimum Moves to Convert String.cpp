#include <bits/stdc++.h>
using namespace std;

int minimumMoves(string s)
{
    int n = s.size();
    int res = 0;
    int index = 0;
    while (index < n)
    {
        if (s[index] == 'X')
        {
            index += 2;
            res++;
        }
        index += 1;
    }
    return res;
}