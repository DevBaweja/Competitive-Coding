#include <bits/stdc++.h>
using namespace std;


// If there was only one repeated only once
// Using XOR
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int x = nums[0];
    for(int i=1; i<n; i++){
        x ^= i;
        x ^= nums[i];
    }
    return x;
}

// Visited
// Time - O(n)
// Space - O(n)
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    vector<int> vis(n + 1, false);
    for (int el : nums)
    {
        if (vis[el])
            return el;
        vis[el] = true;
    }
    return -1;
}

// Time - O(n*log(n))
// Space - O(1)
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=1; i<n; i++) {
        if(nums[i-1] == nums[i])
            return nums[i];
    }
    return -1;
}

// TODO
// Using Linked List Cycle Method and finding first element
// Using Binary Search