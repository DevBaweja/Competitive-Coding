#include <bits/stdc++.h>
using namespace std;

// Maths
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int el : nums)
        sum += el;
    return (n * (n + 1)) / 2 - sum;
}

// XOR
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= (nums[i] ^ (i + 1));
    return x;
}

// Sorting and Binary Search
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > mid)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}