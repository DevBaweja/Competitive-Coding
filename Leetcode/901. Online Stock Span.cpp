
#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;
int next(int price)
{
    int count = 0;
    while (!s.empty() && s.top().first <= price)
    {
        count += s.top().second;
        s.pop();
    }
    count++;
    s.push({price, count});
    return count;
}