#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> lis(n, 0);
    vector<int> lds(n, 0);

    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
                maxi = max(maxi, lis[j]);
        }
        lis[i] = maxi + 1;
    }

    lds[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int maxi = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i])
                maxi = max(maxi, lds[j]);
        }
        lds[i] = maxi + 1;
    }

    int res = 1;
    for (int i = 0; i < n; i++)
        res = max(res, lis[i] + lds[i] - 1);
    return res;
}