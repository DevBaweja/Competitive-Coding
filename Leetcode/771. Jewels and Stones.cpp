#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    unordered_set<char> s;
    for (char el : jewels)
        s.insert(el);
    int res = 0;
    for (char el : stones)
    {
        if (s.find(el) != s.end())
            res++;
    }
    return res;
}