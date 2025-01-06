#include <bits/stdc++.h>
using namespace std;

// Hashing
// Time - O(n)
// Space- O(n)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
            res = {m[target - nums[i]], i};
        m[nums[i]] = i;
    }
    return res;
}

// Two Pointer
// Time - O(nlog(n))
// Space - O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++)
        v[i] = {nums[i], i};
    sort(v.begin(), v.end());
    while(l < r) {
        int sum = v[l].first + v[r].first;
        if(sum == target) 
            return {v[l].second,v[r].second};
        if(sum < target)
            l++;
        else
            r--;
    }
    return {-1, -1};
}