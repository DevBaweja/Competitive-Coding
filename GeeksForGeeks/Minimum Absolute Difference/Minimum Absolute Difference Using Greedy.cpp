#include <bits/stdc++.h>
using namespace std;

// Greedy
int minimumAbsoluteDifference(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        res = min(res, nums[i + 1] - nums[i]);
    return res;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << minimumAbsoluteDifference(nums);
    return 0;
}