#include <bits/stdc++.h>
using namespace std;

// Brute Force
int minTaps(int n, vector<int> &ranges)
{
    int mini = 0, maxi = 0;
    int open = 0;
    while (maxi < n)
    {

        for (int index = 0; index <= n; index++)
            if (index - ranges[index] <= mini && index + ranges[index] > maxi)
                maxi = index + ranges[index];
        open++;
        if (mini == maxi)
            return -1;
        mini = maxi;
    }
    return open;
}

// TODO
// DP