#include <bits/stdc++.h>
using namespace std;

// Probabilities
int pickIndex(vector<int> &w)
{
    int n = w.size();
    vector<float> p(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += w[i];
    for (int i = 0; i < n; i++)
        p[i] = (float)w[i] / (float)sum;
    for (int i = 1; i < n; i++)
        p[i] += p[i - 1];
    float r = (float)rand() / (float)RAND_MAX;
    for (int i = 0; i < n; i++)
        if (r <= p[i])
            return i;
    return n - 1;
}

int pickIndex(vector<int> &w)
{
    int n;
    vector<int> p;
    int sum;
    n = w.size();
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += w[i];
        p.push_back(sum);
    }
    int r = rand() % sum;
    for (int i = 0; i < n; i++)
        if (r <= p[i])
            return i;
    return n - 1;
}