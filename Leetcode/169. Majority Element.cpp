#include <bits/stdc++.h>
using namespace std;

// Since element is more than n/2. so it will occupy middle after sorting
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n/2];
}

// Hashing
// Time - O(n)
// Space - O(n)
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
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int el: nums) {
        mp[el]++;
        if(mp[el] > n/2)
            return el;
    }
    return -1;
}


// Moore Voting Algorithm
// Time - O(n)
// Space - O(1)
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

// Moore Voting Algorithm
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int el = nums[0];
    int count = 1;
    for(int i=1; i<n; i++){
        count += (el == nums[i]) ? 1: -1;
        if(count < 0) {
            el = nums[i];
            count = 1;
        }
    }
    return el;
}