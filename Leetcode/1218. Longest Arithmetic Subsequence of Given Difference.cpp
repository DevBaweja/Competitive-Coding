#include <bits/stdc++.h>
using namespace std;

// LIS
int longestSubsequence(vector<int> &arr, int diff)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] - arr[j] == diff)
                maxi = max(maxi, dp[j]);
        }
        dp[i] = 1 + maxi;
        res = max(res, dp[i]);
    }
    return res;
}

// Hashing
int longestSubsequence(vector<int> &arr, int diff)
{
    int n = arr.size();
    unordered_map<int, int> m;
    int res = 0;
    for (int el : arr)
    {
        m[el] = 1 + m[el - diff];
        res = max(res, m[el]);
    }
    return res;
}