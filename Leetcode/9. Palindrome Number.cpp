#include <bits/stdc++.h>
using namespace std;

// Two Pointer
bool isPalindrome(int x)
{
    string el = to_string(x);
    int n = el.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (el[l++] != el[r--])
            return false;
    }
    return true;
}