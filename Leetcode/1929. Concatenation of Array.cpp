#include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(2 * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[i];
        ans[i + n] = nums[i];
    }
    return ans;
}

vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        nums.push_back(nums[i]);
    return nums;
}