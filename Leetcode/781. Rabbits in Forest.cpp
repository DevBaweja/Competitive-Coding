#include <bits/stdc++.h>
using namespace std;

// Hashing and Counting
int numRabbits(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int el : nums)
        m[el]++;
    int res = 0;
    for (pair<int, int> p : m)
    {
        int den = p.first + 1, num = p.second;
        int quo = num / den;
        res += quo * den;
        int rem = num % den;
        if (rem)
            res += den;
    }
    return res;
}