#include <bits/stdc++.h>
using namespace std;

vector<int> find3Numbers(vector<int> nums, int n)
{
    vector<int> smallest(n);
    smallest[0] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] <= smallest[i - 1])
            smallest[i] = nums[i - 1];
        else
            smallest[i] = smallest[i - 1];
    }

    vector<int> greatest(n);
    greatest[n - 1] = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i + 1] >= greatest[i + 1])
            greatest[i] = nums[i + 1];
        else
            greatest[i] = greatest[i + 1];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (smallest[i] < nums[i] && nums[i] < greatest[i])
            return {smallest[i], nums[i], greatest[i]};
    }
    return {};
}