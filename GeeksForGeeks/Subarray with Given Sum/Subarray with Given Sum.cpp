#include <bits/stdc++.h>
using namespace std;

// Time - O(n2)
// Two Loops
vector<int> subarraySum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
                return {i + 1, j + 1};
            if (sum > target)
                break;
        }
    }
    return {-1};
}

vector<int> subarraySum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int j = i;
        while (j < n && sum < target)
            sum += arr[j++];
        if (sum == target)
            return {i + 1, j};
    }
    return {-1};
}

// Time - O(n2)
// Space - O(n)
// Prefix Sum
vector<int> subarraySum(int arr[], int n, int target)
{
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int sum = prefix[j] - prefix[i];
            if (sum == target)
                return {i + 1, j};
            if (sum > target)
                break;
        }
    return {-1};
}

// Time - O(n)
// Space - O(1)
// Sliding Window
vector<int> subarraySum(int arr[], int n, int target)
{
    int low = 0;
    int sum = 0;
    for (int high = 0; high < n; high++)
    {
        sum += arr[high];
        while (sum > target)
            sum -= arr[low++];
        if (sum == target)
            return {low + 1, high + 1};
    }

    return {-1};
}

// Time - O(n)
// Space - O(n)
// Hashing
// Handles Negative Numbers
vector<int> subarraySum(int arr[], int n, int target)
{
    unordered_map<int, int> m;
    m[0] = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.find(sum - target) != m.end())
            return {m[sum - target] + 1, i + 1};
        m[sum] = i + 1;
    }
    return {-1};
}

// Count
// Cumulative Prefix and Hashing
int subArraySum(int arr[], int n, int target)
{
    int sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.find(sum - target) != m.end())
            count += m[sum - target];
        m[sum]++;
    }
    return count;
}