#include <bits/stdc++.h>
using namespace std;

// Brute Force
int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)

                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
                    count++;
    return count;
}