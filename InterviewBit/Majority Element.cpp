#include <bits/stdc++.h>
using namespace std;

// Hashing
int majorityElement(const vector<int> &A)
{
    int n = A.size();
    int c = ceil(n / 2.0);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;
        if (m[A[i]] == c)
            return A[i];
    }
    return -1;
}
