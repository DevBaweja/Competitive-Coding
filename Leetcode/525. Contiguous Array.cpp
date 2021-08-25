#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> m;
    int res = 0;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int el = nums[i];
        if (el)
            sum++;
        else
            sum--;
        if (m.find(sum) != m.end())
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    return res;
}