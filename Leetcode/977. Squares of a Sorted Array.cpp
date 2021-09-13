#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n)
        c[k++] = a[i++];
    while (j < m)
        c[k++] = b[j++];
    return c;
}

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> a;
    vector<int> b;
    int index = 0;
    while (index < n && nums[index] < 0)
    {
        a.push_back(nums[index] * nums[index]);
        index++;
    }
    while (index < n)
    {
        b.push_back(nums[index] * nums[index]);
        index++;
    }
    reverse(a.begin(), a.end());
    return merge(a, b);
}

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int a = nums[i] * nums[i];
        int b = nums[j] * nums[j];
        if (a <= b)
        {
            res.push_back(b);
            j--;
        }
        else
        {
            res.push_back(a);
            i++;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}