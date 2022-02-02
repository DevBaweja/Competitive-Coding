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

// Moore Voting Algorithm
int majorityElement(vector<int> &nums)
{
    int count = 1;
    int cand = nums[0];
    for (int el : nums)
    {
        if (el == cand)
            count++;
        else
            count--;
        if (count == 0)
        {
            cand = el;
            count = 1;
        }
    }
    return cand;
}