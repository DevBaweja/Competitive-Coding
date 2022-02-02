#include <bits/stdc++.h>
using namespace std;

// BFS
int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int sum = 0;
    for (int el : nums)
        sum += el;
    if (sum == x)
        return n;

    queue<vector<int>> q;
    q.push({x, 0, n - 1, 0});

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            vector<int> v = q.front();
            q.pop();
            int rem = v[0], left = v[1], right = v[2], step = v[3];
            if (left > right)
                continue;
            if (!rem)
                return step;
            if (nums[left] <= rem)
                q.push({rem - nums[left], left + 1, right, step + 1});
            if (nums[right] <= rem)
                q.push({rem - nums[right], left, right - 1, step + 1});
        }
    }

    return -1;
}

// Prefix Sum and Hashing
int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int sum = 0;
    unordered_map<int, int> m;
    int mini = INT_MAX;
    for (int i = 0; i < 2 * n; i++)
    {
        int el = nums[i % n];
        sum += el;
        if (m.find(sum - x) != m.end())
        {
            int start = m[sum - x];
            int end = i;
            if (start <= n && end >= n - 1 && end - start + 1 <= n)
                mini = min(mini, end - start + 1);
        }
        m[sum] = i + 1;
    }

    return mini != INT_MAX ? mini : -1;
}

// TODO
// Sliding Window
