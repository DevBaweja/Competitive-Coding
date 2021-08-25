#include <bits/stdc++.h>
using namespace std;

// Hashing
int majorityElement(int A[], int size)
{
    int c = ceil(size / 2.0);
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
    {
        m[A[i]]++;
        if (m[A[i]] > size / 2)
            return A[i];
    }
    return -1;
}

// Moore Voting
int majorityElement(int A[], int size)
{
    int count = 1;
    int cand = A[0];
    for (int i = 1; i < size; i++)
    {
        if (A[i] == cand)
            count++;
        else
            count--;
        if (!count)
        {
            cand = A[i];
            count = 1;
        }
    }

    int check = 0;
    for (int i = 0; i < size; i++)
        if (A[i] == cand)
            check++;
    if (check > size / 2)
        return cand;
    return -1;
}

// Maintain Index Moores Voting
int majorityElement(vector<int> &num)
{
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < num.size(); i++)
    {
        num[majorityIndex] == num[i] ? count++ : count--;
        if (count == 0)
        {
            majorityIndex = i;
            count = 1;
        }
    }

    return num[majorityIndex];
}