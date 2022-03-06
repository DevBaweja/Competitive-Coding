#include <bits/stdc++.h>
using namespace std;

// Brute Force
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    set<pair<int, int>> res;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(nums[i] - nums[j]) == k && res.find({nums[i], nums[j]}) == res.end() && res.find({nums[j], nums[i]}) == res.end())
            {
                count++;
                res.insert({nums[i], nums[j]});
            }
    return count;
}

int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    set<pair<int, int>> res;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(nums[i] - nums[j]) == k && res.find({nums[i], nums[j]}) == res.end())
            {
                count++;
                res.insert({nums[i], nums[j]});
                res.insert({nums[j], nums[i]});
            }
    return count;
}

// Hashing and Sorting
// Time - O(n log(n))
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    vector<int> s;
    unordered_map<int, int> freq;
    for (int el : nums)
        freq[el]++;
    int sub = 0;
    for (pair<int, int> el : freq)
    {
        if (el.second >= 2)
            sub++;
        s.push_back(el.first);
    }
    if (!k)
        return sub;

    sort(s.begin(), s.end());
    unordered_set<int> m;
    for (int el : s)
    {
        // count += m.find(el+k) != m.end();
        count += m.find(el - k) != m.end();
        m.insert(el);
    }
    return count;
}

// Binary Search
// Time - O(n log(n))
int binarySearch(vector<int> &nums, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == key)
            return mid;
        if (key < nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (i != 0 && nums[i] == nums[i - 1])
            i++;
        int low = i + 1;
        int high = n - 1;
        int key = nums[i] + k;
        if (binarySearch(nums, low, high, key) != -1)
            count++;
    }
    return count;
}

// Hashing
// Time - O(n)
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    vector<int> s;
    unordered_map<int, int> freq;
    for (int el : nums)
        freq[el]++;
    int sub = 0;
    for (pair<int, int> el : freq)
    {
        if (el.second >= 2)
            sub++;
        s.push_back(el.first);
    }
    if (!k)
        return sub;

    unordered_set<int> m;
    for (int el : s)
    {
        count += m.find(el + k) != m.end();
        count += m.find(el - k) != m.end();
        m.insert(el);
    }
    return count;
}

// Hashing
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    vector<int> s;
    map<int, int> freq;
    for (int el : nums)
        freq[el]++;
    for (pair<int, int> el : freq)
        if ((k == 0 && el.second > 1) || (k > 0 && freq.find(el.first + k) != freq.end()))
            count++;
    return count;
}

// Two Hashmap
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    unordered_set<int> s;
    unordered_set<int> f;
    for (int el : nums)
    {
        if (s.find(el - k) != s.end())
            f.insert(el - k);
        if (s.find(el + k) != s.end())
            f.insert(el);
        s.insert(el);
    }
    return f.size();
}
int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    unordered_set<int> s;
    unordered_set<int> f;
    for (int el : nums)
    {
        if (s.find(el - k) != s.end())
            f.insert(el);
        if (s.find(el + k) != s.end())
            f.insert(el + k);
        s.insert(el);
    }

    return f.size();
}