#include <bits/stdc++.h>
using namespace std;

int minimizeTheDifference(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[n - 1].size();
    unordered_set<int> prev;
    prev.insert(0);
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> next;
        for (int j = 0; j < m; j++)
        {
            for (int el : prev)
            {
                next.insert(el + mat[i][j]);
            }
        }

        prev = next;
    }

    int mini = INT_MAX;
    for (int el : prev)
        mini = min(mini, abs(target - el));
    return mini;
}