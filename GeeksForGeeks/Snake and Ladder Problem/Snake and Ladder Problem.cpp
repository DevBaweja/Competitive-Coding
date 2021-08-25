#include <bits/stdc++.h>
using namespace std;

int minThrow(int n, int arr[])
{
    int dest = 30;
    vector<int> slp(dest + 1, -1);
    for (int i = 0; i < n; i++)
        slp[arr[2 * i]] = arr[2 * i + 1];

    queue<pair<int, int>> q;
    q.push({1, 0});

    while (!q.empty())
    {
        pair<int, int> t = q.front();
        int reach = t.first;
        int step = t.second;
        q.pop();
        if (reach >= dest)
            return step;

        int len = 6;
        while (len--)
        {
            int next = reach + len + 1;
            if (slp[next] != -1)
                q.push({slp[next], step + 1});
            else
                q.push({next, step + 1});
        }
    }
}
// optimized with vis
int minThrow(int n, int arr[])
{
    int dest = 30;
    vector<int> slp(dest + 1, -1);
    vector<int> vis(dest + 1, 0);
    for (int i = 0; i < n; i++)
        slp[arr[2 * i]] = arr[2 * i + 1];

    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = 1;

    while (!q.empty())
    {
        pair<int, int> t = q.front();
        int reach = t.first;
        int step = t.second;
        q.pop();
        if (reach == dest)
            return step;

        int len = 6;
        while (len--)
        {
            int next = reach + len + 1;
            if (next > dest)
                continue;
            if (!vis[next])
            {
                vis[next] = 1;
                if (slp[next] != -1)
                    q.push({slp[next], step + 1});
                else
                    q.push({next, step + 1});
            }
        }
    }
}