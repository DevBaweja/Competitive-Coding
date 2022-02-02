#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool checkIfExist(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == 2 * arr[j] || (arr[j] % 2 == 0 && arr[i] == arr[j] / 2))
                return true;

    return false;
}

// Hashing
bool checkIfExist(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(2 * arr[i]) != s.end() ||
            (arr[i] % 2 == 0 && s.find(arr[i] / 2) != s.end()))
            return true;
        s.insert(arr[i]);
    }
    return false;
}