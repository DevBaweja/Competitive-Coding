#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int A[], int n, int k)
{
    vector<int> res;
    map<int, int> m;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (!m[A[i]])
            count++;
        m[A[i]]++;
    }
    res.push_back(count);

    for (int i = k; i < n; i++)
    {
        m[A[i - k]]--;
        if (!m[A[i - k]])
            count--;

        if (!m[A[i]])
            count++;
        m[A[i]]++;

        res.push_back(count);
    }
    return res;
}