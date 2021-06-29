#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    vector<int> v(n, 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && price[i] >= s.top().first)
            s.pop();
        v[i] = !s.empty() ? i - s.top().second : i + 1;
        s.push({price[i], i});
    }
    return v;
}