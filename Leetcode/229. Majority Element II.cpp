#include <bits/stdc++.h>
using namespace std;

// Hashing
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = floor(n / 3);
    unordered_map<int, int> m;
    for (int el : nums)
        m[el]++;
    vector<int> res;
    for (pair<int, int> p : m)
    {
        if (p.second > count)
            res.push_back(p.first);
    }
    return res;
}

// Moore Voting Algorithm
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int n1 = 0, n2 = 0;
    int c1 = 0, c2 = 0;
    for (int el : nums)
    {
        if (el == n1)
            c1++;
        else if (el == n2)
            c2++;
        else if (!c1)
        {
            n1 = el;
            c1 = 1;
        }
        else if (!c2)
        {
            n2 = el;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    c1 = 0;
    c2 = 0;
    for (int el : nums)
    {
        if (el == n1)
            c1++;
        if (el == n2)
            c2++;
    }
    int req = floor(n / 3);
    vector<int> res;
    if (c1 > req)
        res.push_back(n1);
    if (n1 != n2 && c2 > req)
        res.push_back(n2);
    return res;
}

// This will not work
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int n1 = 0, n2 = 0;
    int c1 = 0, c2 = 0;
    for(int el: nums) {
        c1 += (n1 == el) ? 1: -1;
        if(c1 < 0) {
            n1 = el;
            c1 = 1;
        }
    }
    for(int el: nums) {
        if(n1 != el) {
            c2 += (n2 == el) ? 1: -1;
            if(c2 < 0) {
                n2 = el;
                c2 = 1;
            }
        }
    }
    c1 = 0; c2 = 0;
    for (int el : nums)
    {
        if (el == n1)
            c1++;
        if (el == n2)
            c2++;
    }
    int req = n / 3;
    vector<int> res;
    if (c1 > req)
        res.push_back(n1);
    if (n1 != n2 && c2 > req)
        res.push_back(n2);
    return res;
}

// Extended Moris Voting Algorithm
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int n1 = 0, n2 = 0;
    int c1 = 0, c2 = 0;
    for(int el: nums) {
        // Do it in this order only
        if(n1 == el) {
            c1++;
        } else if(n2 == el) {
            c2++;
        } else if(c1 == 0) {
            n1 = el;
            c1 = 1;
        } else if(c2 == 0) {
            n2 = el;
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }

    c1 = 0; c2 = 0;
    for (int el : nums)
    {
        if (el == n1)
            c1++;
        if (el == n2)
            c2++;
    }
    int req = n / 3;
    vector<int> res;
    if (c1 > req)
        res.push_back(n1);
    if (n1 != n2 && c2 > req)
        res.push_back(n2);
    return res;
}