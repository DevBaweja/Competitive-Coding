#include <bits/stdc++.h>
using namespace std;

// Brute Force
int subarraySum(vector<int> &nums, int target)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            count += sum == target;
        }
    }
    return count;
}

// Prefix Sum and Hashing
int subarraySum(vector<int> &nums, int target)
{
    int n = nums.size();
    int count = 0;
    int sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (m.find(sum - target) != m.end())
            count += m[sum - target];
        m[sum]++;
    }
    return count;
}

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    mp[sum] = 1;
    for(int el: nums) {
        sum += el;
        if(mp.find(sum - k) != mp.end()) {
            res += mp[sum-k];
        }
        mp[sum]++;
    }
    return res;
}