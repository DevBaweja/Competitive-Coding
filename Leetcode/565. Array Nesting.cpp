#include <bits/stdc++.h>
using namespace std;

int arrayNesting(vector<int> &nums)
{
    int n = nums.size();

    int res = 0;
    vector<bool> vis(n, false);
    for (int el : nums)
    {
        if (!vis[el])
        {
            vis[el] = true;
            int count = 1;

            while (!vis[nums[el]])
            {
                vis[nums[el]];
                count++;
                el = nums[el];
            }
            res = max(res, count);
        }
    }
    return res;
}
