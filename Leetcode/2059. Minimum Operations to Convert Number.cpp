#include <bits/stdc++.h>
using namespace std;

bool isValid(int next, vector<bool> &vis, int size)
{
    return (next >= 0 && next <= size && !vis[next]);
}
int minimumOperations(vector<int> &nums, int start, int goal)
{
    int size = 1e3;
    vector<bool> vis(size + 1, false);

    queue<pair<int, int>> q;
    q.push({start, 0});
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int cur = temp.first;
        int step = temp.second;

        for (int el : nums)
        {
            int nexta = cur + el, nextb = cur - el, nextc = cur ^ el;
            if (nexta == goal)
                return step + 1;
            if (nextb == goal)
                return step + 1;
            if (nextc == goal)
                return step + 1;
            if (isValid(nexta, vis, size))
            {
                vis[nexta] = true;
                q.push({nexta, step + 1});
            }
            if (isValid(nextb, vis, size))
            {
                vis[nextb] = true;
                q.push({nextb, step + 1});
            }
            if (isValid(nextc, vis, size))
            {
                vis[nextc] = true;
                q.push({nextc, step + 1});
            }
        }
    }
    return -1;
}