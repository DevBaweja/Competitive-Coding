#include <bits/stdc++.h>
using namespace std;

// Brute Force
int findNumbers(vector<int> &nums)
{
    int res = 0;
    for (int el : nums)
    {
        int count = 0;
        while (el)
        {
            el /= 10;
            count++;
        }
        res += !(count & 1);
    }
    return res;
}
