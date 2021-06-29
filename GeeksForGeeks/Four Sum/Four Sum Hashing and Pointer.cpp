#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &A, int k)
{
    vector<vector<int>> res;
    int n = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && A[i] == A[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && A[j] == A[j - 1])
                continue;
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                int sum = A[i] + A[j] + A[l] + A[r];
                if (sum < k)
                    l++;
                else if (sum > k)
                    r--;
                else
                {
                    res.push_back({A[i], A[j], A[l], A[r]});
                    l++;
                    r--;
                    while (l < r && A[l - 1] == A[l])
                        l++;
                    while (l < r && A[r + 1] == A[r])
                        r--;
                }
            }
        }
    }
    return res;
}