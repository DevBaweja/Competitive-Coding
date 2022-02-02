#include <bits/stdc++.h>
using namespace std;

int minFlips(string target)
{
    int n = target.size();
    char prev = '0';
    int count = 0;
    for (int cur : target)
    {
        count += prev != cur;
        prev = cur;
    }
    return count;
}