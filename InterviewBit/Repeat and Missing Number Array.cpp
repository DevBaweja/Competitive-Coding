#include <bits/stdc++.h>
using namespace std;

// Time - O(n)
// Space - O(n)
vector<int> Solution::repeatedNumber(const vector<int> &nums) {
    int n = nums.size();
    vector<bool> vis(n, false);
    vector<int> res(2, 0);
    for(int el: nums) {
        if(vis[el-1])
            res[0] = el;
        vis[el-1] = true;
    }
    
    for(int i=0; i<n; i++) {
        if(!vis[i])
            res[1] = i+1;
    }
    return res;
}

// Time - O(n*log(n))
// Space - O(1)
vector<int> Solution::repeatedNumber(const vector<int> &v) {
    vector<int> nums = v;
    int n = nums.size();
    vector<int> res(2, 0);
    
    sort(nums.begin(), nums.end());
    bool m = false, d = false;
    for(int i=1; i<=n; i++) {
        if(!m && !d) {
            if(i == nums[i-1] - 1) {
                res[1] = i; // missing
                m = true;
            }
            if(i == nums[i-1] + 1) {
                res[0] = i-1; // duplicate
                d = true;
            }
        } else if (!m) {
            if(i == nums[i-1]) {
                res[1] = i - 1;
                m = true;
            }
        } else if (!d) {
            if(i == nums[i-1]) {
                res[0] = i;
                d = true;
            }
        } else {
            break;
        }
    }
    
    if(!m)
        res[1] = n;
    return res;
}

// Time - O(n*log(n))
// Space - O(1)
// Easier checks
vector<int> Solution::repeatedNumber(const vector<int> &v) {
    vector<int> nums = v;
    int n = nums.size();
    vector<int> res(2, 0);
    
    sort(nums.begin(), nums.end());
    
    for(int i=1; i<n; i++) {
        if(nums[i-1] == nums[i])
            res[0] = nums[i];
        else if(nums[i] - nums[i-1] ==  2) 
            res[1] = (nums[i] + nums[i-1]) / 2;
    }
    
    if(!res[1]) {
        res[1] = nums[n-1] == n ? 1: n;
    }
        
    return res;
}

// Maths
// Time - O(n)
// Space - O(1)
vector<int> Solution::repeatedNumber(const vector<int> &v) {
    vector<int> nums = v;
    int n = nums.size();
    vector<int> res(2, 0);
    
    int diff = 0, sqdiff = 0;
    
    for(int i=1; i<=n; i++) {
        diff += i - nums[i-1];
        sqdiff += i*i - nums[i-1]*nums[i-1];
    }
    
    
    // x -> repeat
    // y -> missing
    // sum + y - x = 1+2+3... = n(n+1)/2
    // y-x = n(n+1)/2 - sum = diff

    // sum^2 + y^2 - x^2 = 1^2 + 2^2 + .. = n(n+1)(2n+1)/6
    // y^2 - x^2 = n(n+1)(2n+1)/6 - sum^2 = sqdiff
    
    // (y-x)(y+x) = sqdiff
    // (y+x) = sqdiff/diff;
    int sum =  sqdiff/diff;
    
    res[1] = (sum + diff)/2;
    res[0] = (sum - diff)/2;
        
    return res;
}

// XOR
// Time - O(n)
// Space - O(1)
vector<int> Solution::repeatedNumber(const vector<int> &v) {
    // x^y
     vector<int> nums = v;
    int n = nums.size();
    vector<int> res(2, 0);
    
    int r = 0;
    for(int i=1; i<=n; i++) {
        r ^= (i^nums[i-1]);
    }
    // find different bit from right
    int rsb = r & -r;
    // create two bucket for 0 and 1
    int a = 0, b = 0;
    for(int i=1; i<=n; i++) {
        if(i & rsb)
            a ^= i;
        else 
            b ^= i;
        if(nums[i-1] & rsb)
            a ^= nums[i-1];
        else
            b ^= nums[i-1];
    }
    res[0] = a; res[1] = b;
    for(int el: nums) {
        if(b == el) {
            swap(res[0], res[1]);
            break;
        }
    }
    return res;
}

