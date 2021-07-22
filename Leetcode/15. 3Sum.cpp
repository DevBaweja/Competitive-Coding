#include <bits/stdc++.h>
using namespace std;

// Sorting and Two Pointer 
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 1; i++)
    {
        int target = -nums[i];
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int subsum = nums[left] + nums[right];
            if (subsum < target)
                left++;
            if (subsum > target)
                right--;
            if (subsum == target)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left + 1] == nums[left])
                    left++;
                while (left < right && nums[right - 1] == nums[right])
                    right--;
                left++;
                right--;
            }
        }

        while (i < n - 1 && nums[i] == nums[i + 1])
            i++;
    }
    return res;
}