#include <bits/stdc++.h>
using namespace std;

// Prefix Sum
class NumArray
{
public:
    vector<int> nums;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];
        this->nums = nums;
    }

    int sumRange(int left, int right)
    {
        int a = !left ? 0 : nums[left - 1];
        int b = nums[right];
        return b - a;
    }
};

// Prefix Sum
class NumArray {
public:
    vector<int> prefix;
    // O(n)
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.push_back(nums[0]);
        for(int i=1; i<n; i++)
            prefix.push_back(prefix.back() + nums[i]);
    }
    
    // O(1) for every query
    int sumRange(int left, int right) {
        if(!left)  return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};

// TODO
// Lazy propagation for optimization
