#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool canBeIncreasing(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int temp = nums[i];
        nums.erase(nums.begin() + i);
        bool flag = true;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i - 1] >= nums[i])
                flag = false;
            if (!flag)
                break;
        }
        if (flag)
            return true;
        nums.insert(nums.begin() + i, temp);
    }
    return false;
}

// Optimal