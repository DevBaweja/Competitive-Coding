#include <bits/stdc++.h>
using namespace std;
// Brute Force Target Sum and Greedy
// Time - O(n2)
int maxNonOverlapping(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == target)
                v.push_back({j, i});
        }
    }
    int k = v.size();
    if (!k)
        return 0;

    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++)
        swap(v[i].first, v[i].second);

    int count = 1;
    int time = v[count - 1].second;

    for (int i = 1; i < k; i++)
    {
        if (v[i].first > time)
        {
            count++;
            time = v[i].second;
        }
    }
    return count;
}

// Hashing Target Sum Subset && Greedy
// Time - O(nlog(n)) to O(n)
int maxNonOverlapping(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<pair<int, int>> v;

    int sum = 0;
    unordered_map<int, vector<int>> m;
    m[sum] = {0};

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (m.find(sum - target) != m.end())
        {
            for (int j : m[sum - target])
                v.push_back({i, j});
        }
        m[sum].push_back(i + 1);
    }

    int k = v.size();
    if (!k)
        return 0;

    // sort(v.begin(), v.end());

    for (int i = 0; i < k; i++)
        swap(v[i].first, v[i].second);

    int count = 1;
    int time = v[count - 1].second;

    for (int i = 1; i < k; i++)
    {
        if (v[i].first > time)
        {
            count++;
            time = v[i].second;
        }
    }
    return count;
}

// TODO
// Hashing and Greedy
// Time - O(n)