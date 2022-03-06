#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (!n)
        return 0;
    int cur = 1;
    for (int index = 1; index < n; index++)
        if (nums[index - 1] != nums[index])
            nums[cur++] = nums[index];
    return cur;
}