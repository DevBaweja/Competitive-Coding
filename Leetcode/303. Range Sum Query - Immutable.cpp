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