#include <bits/stdc++.h>
using namespace std;

// Prefix and Suffix
bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();
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
            return true;
    }
    return false;
}

bool increasingTriplet(vector<int> &nums)
{
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int el : nums)
    {
        if (el <= c1)
            c1 = el;
        else if (el <= c2)
            c2 = el;
        else
            return true;
    }
    return false;
}