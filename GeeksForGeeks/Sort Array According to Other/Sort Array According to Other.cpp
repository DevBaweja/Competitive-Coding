#include <bits/stdc++.h>
using namespace std;

// Counting Sort
vector<int> sortA1ByA2(vector<int> A, int n, vector<int> B, int m)
{
    vector<int> res(n);

    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
        maximum = max(maximum, A[i]);
    vector<int> freq(maximum);
    for (int i = 0; i < n; i++)
        freq[A[i] - 1]++;

    int index = 0;
    for (int i = 0; i < m; i++)
    {
        if (B[i] > maximum)
            continue;
        if (freq[B[i] - 1])
        {
            int k = freq[B[i] - 1];
            while (k--)
                res[index++] = B[i];
            freq[B[i] - 1] = 0;
        }
    }

    for (int i = 0; i < maximum; i++)
    {
        if (freq[i])
        {
            int k = freq[i];
            while (k--)
                res[index++] = i + 1;
            freq[i] = 0;
        }
    }

    return res;
}