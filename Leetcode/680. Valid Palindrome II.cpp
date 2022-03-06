#include <bits/stdc++.h>
using namespace std;

// Greedy selecting left or right
bool validPalindrome(string s)
{
    int n = s.size();
    bool power;
    int l, r;
    bool left = true;
    power = true;
    l = 0;
    r = n - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (!power)
                left = false;
            if (power)
                power = false;
        }
        else
            r--;
        l++;
    }
    bool right = true;
    power = true;
    l = 0;
    r = n - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (!power)
                right = false;
            if (power)
                power = false;
        }
        else
            l++;
        r--;
    }
    return left || right;
}