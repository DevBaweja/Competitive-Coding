#include <bits/stdc++.h>
using namespace std;

// Time - O(n2)
// Two Loops
vector<int> subarraySum(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int j = i;
        while (j < n && sum < s)
            sum += arr[j++];
        if (sum == s)
            return {i + 1, j};
    }
    return {-1};
}

// Time - O(n2)
// Space - O(n)
// Prefix Sum
vector<int> subarraySum(int arr[], int n, int s)
{
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (prefix[j] - prefix[i] == s)
                return {i + 1, j};
    return {-1};
}

// Time - O(n)
// Space - O(n)
// Hashing

// Time - O(n)
// Space - O(n)
// Sliding Window