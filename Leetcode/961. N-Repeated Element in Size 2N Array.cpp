#include <bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] == A[j])
                return A[i];
        }
    }
    return -1;
}