#include <bits/stdc++.h>
using namespace std;

// BFS
bool canReach(vector<int> &nums, int start)
{
    int n = nums.size();
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (!nums[temp])
            return true;
        int left = temp - nums[temp];
        int right = temp + nums[temp];
        if (left >= 0 && !vis[left])
        {
            q.push(left);
            vis[left] = true;
        }
        if (right <= n - 1 && !vis[right])
        {
            q.push(right);
            vis[right] = true;
        }
    }
    return false;
}