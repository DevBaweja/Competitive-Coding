#include <bits/stdc++.h>
using namespace std;

void makeBST(vector<int> &nums, int l, int h, vector<int> &res)
{
    if (l > h)
        return;

    int m = (l + h) / 2;
    res.push_back(nums[m]);

    makeBST(nums, l, m - 1, res);
    makeBST(nums, m + 1, h, res);
}

vector<int> sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, h = n - 1;
    vector<int> res;
    makeBST(nums, l, h, res);
    return res;
}