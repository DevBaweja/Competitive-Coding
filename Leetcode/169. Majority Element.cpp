#include <bits/stdc++.h>
using namespace std;

// Hashing
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        freq[nums[i]]++;

    for (auto k : freq)
    {
        if (k.second > n / 2)
            return k.first;
    }
    return -1;
}