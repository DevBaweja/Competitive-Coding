#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    int n = people.size();
    vector<vector<int>> ans(n, vector<int>{-1, -1});
    sort(people.begin(), people.end(), compare);

    for (int i = 0; i < n; i++)
    {
        vector<int> el = people[i];
        int count = el[1];
        for (int j = 0; j < n; j++)
        {
            int h = ans[j][0];
            if (h == -1 && count == 0)
            {
                ans[j] = el;
                break;
            }
            else if (h == -1 || h >= el[0])
                count--;
        }
    }
    return ans;
}