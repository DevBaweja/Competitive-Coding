#include <bits/stdc++.h>
using namespace std;

// Sorting
// Time - O(nlog(n))
// Space - O(n)
vector<int> maxSubsequence(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {nums[i], i};

    sort(v.begin(), v.end());
    vector<pair<int, int>> res(k);
    for (int i = 0; i < k; i++)
        res[i] = {v[n - i - 1].second, v[n - i - 1].first};
    sort(res.begin(), res.end());
    vector<int> ans;
    for (pair<int, int> p : res)
        ans.push_back(p.second);
    return ans;
}

// Sorting and Hashing
// Time - O(nlog(n))
// Space - O(n)
vector<int> maxSubsequence(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
        m[v[n - i - 1]]++;
    vector<int> ans(k);
    int index = 0;
    for (int el : nums)
        if (--m[el] >= 0)
            ans[index++] = el;
    return ans;
}

// Priority Queue
vector<int> maxSubsequence(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < k; i++)
        pq.push({nums[i], i});
    for (int i = k; i < n; i++)
    {
        pair<int, int> el = pq.top();
        if (el.first < nums[i])
        {
            pq.pop();
            pq.push({nums[i], i});
        }
    }

    vector<pair<int, int>> res(k);
    int index = 0;
    while (!pq.empty())
    {
        res[index++] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < k; i++)
        swap(res[i].first, res[i].second);
    sort(res.begin(), res.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
        ans[i] = res[i].second;
    return ans;
}

// Kth largest element
// Partition requires pivot
// Time - O(n + klog(k))
vector<int> maxSubsequence(vector<int> &nums, int k)
{
    // kth largest element
    int n = nums.size();
    if (k == n)
        return nums;

    vector<int> v(nums.begin(), nums.end());
    nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());

    int el = v[k - 1];
    //  int cnt = count(v.begin(), v.begin() + k, el);
    int cnt = 0;
    for (int i = 0; i < k; i++)
        cnt += (el == v[i]);

    vector<int> res(k);
    int index = 0;
    for (int i = 0; i < n; i++)
        if (el < nums[i] || (el == nums[i] && --cnt >= 0))
            res[index++] = nums[i];
    return res;
}