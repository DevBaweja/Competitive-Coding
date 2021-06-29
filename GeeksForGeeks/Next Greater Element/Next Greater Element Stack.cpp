#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> s;
    vector<long long> v(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        v[i] = !s.empty() ? s.top() : -1;
        s.push(arr[i]);
    }
    return v;
}