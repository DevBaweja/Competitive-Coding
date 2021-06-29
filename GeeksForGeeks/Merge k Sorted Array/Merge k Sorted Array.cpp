#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> point(k, 0);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < k; i++)
        pq.push({arr[i][0], i});
    vector<int> res;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        res.push_back(p.first);
        int index = p.second;
        if (point[index] == k - 1)
            continue;
        point[index]++;
        pq.push({arr[index][point[index]], index});
    }
    return res;
}