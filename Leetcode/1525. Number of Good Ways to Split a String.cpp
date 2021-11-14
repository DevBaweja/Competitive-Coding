#include <bits/stdc++.h>
using namespace std;

// Hashing
// Time - O(n2)
int numSplits(string s)
{
    int n = s.size();
    int count = 0;
    for (int mid = 0; mid < n; mid++)
    {
        unordered_set<int> sl, sr;
        for (int left = mid; left >= 0; left--)
            sl.insert(s[left]);
        for (int right = mid + 1; right < n; right++)
            sr.insert(s[right]);
        if (sl.size() == sr.size())
            count++;
    }
    return count;
}

// Hashing and Sliding Window
// Time - O(n)
int numSplits(string s)
{
    int n = s.size();
    int count = 0;

    unordered_map<int, int> ml, mr;
    ml[s[0]]++;
    for (int i = 1; i < n; i++)
        mr[s[i]]++;

    count += ml.size() == mr.size();

    for (int mid = 1; mid < n; mid++)
    {
        ml[s[mid]]++;
        mr[s[mid]]--;
        if (!mr[s[mid]])
            mr.erase(s[mid]);
        count += ml.size() == mr.size();
    }
    return count;
}