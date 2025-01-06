int Solution::solve(vector<int> &nums, int k) {
    int n = nums.size();
    int res = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    mp[sum] = 1;
    for(int el: nums) {
        sum ^= el;
        if(mp.find(sum^k) != mp.end()) {
            res += mp[sum^k];
        }
        mp[sum]++;
    }
    return res;
}

// This only works
// [..........]
// [_y_, __b__] where b is target
// [_____x____]
// x = y^b where x is sum
// x = y^b is equal to y = x^b by xoring b on both sides