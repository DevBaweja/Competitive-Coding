#include <bits/stdc++.h>
using namespace std;

// Visited
// Space - O(n)
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    vector<int> vis(n + 1, false);
    for (int el : nums)
    {
        if (vis[el])
            return el;
        vis[el] = true;
    }
    return -1;
}