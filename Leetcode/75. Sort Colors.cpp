#include <bits/stdc++.h>
using namespace std;

// Counting Sort
void sortColors(vector<int> &nums)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int el : nums)
    {
        if (el == 0)
            c0++;
        if (el == 1)
            c1++;
        if (el == 2)
            c2++;
    }
    int k = 0;
    while (c0--)
        nums[k++] = 0;
    while (c1--)
        nums[k++] = 1;
    while (c2--)
        nums[k++] = 2;
}

// Dutch Flag Algorithm
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        int el = nums[mid];
        if (el == 0)
            swap(nums[low++], nums[mid++]);
        if (el == 1)
            mid++;
        if (el == 2)
            swap(nums[mid], nums[high--]);
    }
}