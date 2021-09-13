#include <bits/stdc++.h>
using namespace std;

// Time- O(n2)
// Space- O(1)
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = nums[i] ? 1 : -1;
        for (int j = i + 1; j < n; j++)
        {
            sum = nums[j] ? sum + 1 : sum - 1;
            if (!sum)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

// Time- O(n2)
// Space- O(n)
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = nums[i - 1] ? prefix[i - 1] + 1 : prefix[i - 1] - 1;

    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int sum = prefix[j] - prefix[i];
            if (!sum)
                res = max(res, j - i);
        }
    }
    return res;
}

// Time- O(n)
// Space- O(n)
int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = nums[i - 1] ? prefix[i - 1] + 1 : prefix[i - 1] - 1;

    int res = 0;
    unordered_map<int, int> m;

    for (int i = 0; i <= n; i++)
    {
        if (m.find(prefix[i]) != m.end())
            res = max(res, i - m[prefix[i]]);
        else
            m[prefix[i]] = i;
    }
    return res;
}

// Time- O(n)
// Space- O(n)
int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> m;
    int res = 0;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int el = nums[i];
        if (el)
            sum++;
        else
            sum--;
        if (m.find(sum) != m.end())
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    return res;
}