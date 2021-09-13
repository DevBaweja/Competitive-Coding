#include<bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    unordered_map<char, int> m;
    for (int el : s)
        m[el]++;
    priority_queue<int, vector<int>> pq;
    for (pair<int, int> el : m)
        pq.push(el.second);
    int res = 0;
    while (!pq.empty())
    {
        int t = pq.top();
        pq.pop();
        if (!pq.empty() && t == pq.top())
        {
            t--;
            if (t)
                pq.push(t);
            res++;
        }
    }
    return res;
}
