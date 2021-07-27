#include <bits/stdc++.h>
using namespace std;

// Traversal Reachability
bool canCross(vector<int> &stones)
{
    int n = stones.size();
    map<int, set<int>> m;
    for (int i = 0; i < n; i++)
        m[stones[i]] = {};
    m[stones[0]].insert(1);

    for (int i = 0; i < n; i++)
    {
        set<int> op = m[stones[i]];
        for (int j : op)
        {
            int r = j + stones[i];
            if (r == stones[n - 1])
                return true;
            if (m.find(r) != m.end())
            {
                if (j - 1 > 0)
                    m[r].insert(j - 1);
                m[r].insert(j);
                m[r].insert(j + 1);
            }
        }
    }
    return false;
}