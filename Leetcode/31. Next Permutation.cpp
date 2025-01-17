#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return;

    int index = n - 1;
    while (index > 0 && nums[index - 1] >= nums[index])
    {
        index--;
    }

    if (!index)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    int el = index;
    for (int k = index + 1; k < n && nums[k] > nums[index - 1]; k++)
        el = k;

    swap(nums[index - 1], nums[el]);
    reverse(nums.begin() + index, nums.end());
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return;

    int index = n-1;
    // first decreasing element
    while(index > 0 && nums[index-1] >= nums[index])
        index--;
    index--;
    // no decreasing element is found
    if(index == -1) {
        sort(nums.begin(), nums.end());
        return;
    }
    int el = nums[index];

    int k = n-1;
    while(k > index && nums[k] <= el) 
        k--;
    swap(nums[index], nums[k]);

    reverse(nums.begin() + index + 1, nums.end());
}