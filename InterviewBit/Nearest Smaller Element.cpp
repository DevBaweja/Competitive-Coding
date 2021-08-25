#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> left(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && A[i] <= s.top())
            s.pop();
        left[i] = !s.empty() ? s.top() : -1;
        s.push(A[i]);
    }
    return left;
}