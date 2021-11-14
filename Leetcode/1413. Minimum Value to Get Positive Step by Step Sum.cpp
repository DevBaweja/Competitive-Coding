#include <bits/stdc++.h>
using namespace std;

// Binary Search
// Time - O(nlog(n))
bool isPossible(vector<int> &num, int mid)
{
    for (int el : num)
    {
        mid += el;
        if (mid <= 0)
            return false;
    }
    return true;
}

int minStartValue(vector<int> &nums)
{
    int n = nums.size();
    int m = 100;
    int low = 1;
    int high = m * n + 1;

    int res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(nums, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

// Prefix Sum
// Time - O(n)
int minStartValue(vector<int> &nums)
{
    int sum = -1;
    int mini = -1;
    for (int el : nums)
    {
        sum += el;
        mini = min(mini, sum);
    }
    return -mini;
}