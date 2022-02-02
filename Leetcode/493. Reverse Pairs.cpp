#include <bits/stdc++.h>
using namespace std;

// Brute Force
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count += nums[i] > 2ll * nums[j];
        }
    }
    return count;
}