#include <bits/stdc++.h>
using namespace std;

vector<int> numsSameConsecDiff(int n, int k)
{
    queue<int> q;
    int count = 9;
    for (int el = 1; el <= count; el++)
        q.push(el);
    n--;
    while (n--)
    {
        int size = q.size();
        while (size--)
        {
            int temp = q.front();
            q.pop();
            int digit = temp % 10;
            if (k)
            {
                if (digit + k <= count)
                    q.push(temp * 10 + (digit + k) % 10);
                if (digit - k >= 0)
                    q.push(temp * 10 + (digit - k) % 10);
            }
            else
                q.push(temp * 10 + (digit));
        }
    }
    vector<int> v;
    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}