#include <bits/stdc++.h>
using namespace std;

// Xor
// Time- O(n)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= nums[i];
    return x;
}

// Binary Search
// Time- O(log(n))
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int low = 0, high = n - 1;

    // Boundary
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid % 2 == 0)
        {
            if (nums[mid] != nums[mid + 1])
                high = mid - 2;
            else
            {
                low = mid + 2;
                res = low;
            }
        }
        else
        {
            if (nums[mid] != nums[mid - 1])
                high = mid - 1;
            else
            {
                low = mid + 1;
                res = low;
            }
        }
    }
    return res != -1 ? nums[res] : res;
}

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    if (n == 1)
        return nums[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || nums[mid] != nums[mid - 1]) && (mid == n - 1 || nums[mid] != nums[mid + 1]))
            return nums[mid];
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
                high = mid - 2;
            else
                low = mid;
        }
        else
        {
            if (nums[mid] == nums[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int low = 0, high = n - 1;

    // Boundary
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            return nums[mid];

        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid - 1] == nums[mid]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}