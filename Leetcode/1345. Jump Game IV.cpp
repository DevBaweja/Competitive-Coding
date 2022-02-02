#include <bits/stdc++.h>
using namespace std;

// DFS with Backtracking

// BFS
int minJumps(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[nums[i]].push_back(i);

    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    int step = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int temp = q.front();
            q.pop();
            if (temp == n - 1)
                return step;
            int left = temp - 1;
            if (left >= 0 && !vis[left])
            {
                q.push(left);
                vis[left] = true;
            }
            int right = temp + 1;
            if (right <= n - 1 && !vis[right])
            {
                q.push(right);
                vis[right] = true;
            }

            vector<int> list = m[nums[temp]];
            for (int el : list)
            {
                if (!vis[el])
                {
                    q.push(el);
                    vis[el] = true;
                }
            }
        }
        step++;
    }
    return -1;
}

// BFS with pruning
int minJumps(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[nums[i]].push_back(i);

    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    int step = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int temp = q.front();
            q.pop();
            if (temp == n - 1)
                return step;
            int left = temp - 1;
            if (left >= 0 && !vis[left])
            {
                q.push(left);
                vis[left] = true;
            }
            int right = temp + 1;
            if (right <= n - 1 && !vis[right])
            {
                q.push(right);
                vis[right] = true;
            }

            vector<int> &list = m[nums[temp]];
            for (int &el : list)
            {
                if (temp != el && !vis[el])
                {
                    q.push(el);
                    vis[el] = true;
                }
            }
            // Erasing to prevent multiple checks
            m.erase(nums[temp]);
        }
        step++;
    }
    return -1;
}

// TODO
// BiDirectional BFS