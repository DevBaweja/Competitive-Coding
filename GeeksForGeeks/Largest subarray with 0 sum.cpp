
// Prefix Sum
// Time - O(n^2)
int maxLen(vector<int>& nums, int n) {
    vector<int> prefix(n+1, 0);
    for(int i=1; i<=n; i++)
        prefix[i] = prefix[i-1] + nums[i-1];
    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(prefix[j]-prefix[i] == 0) {
                res = max(res, j-i);
            }
        }
    }
    return res;
}

// Prefix Sum with Hashing
int maxLen(vector<int>& nums, int n) {
    unordered_map<int,int> mp;
    int res = 0, sum = 0;
    mp[sum] = -1;
    for(int i=0; i<n; i++) {
        sum += nums[i];
        if(mp.find(sum) != mp.end()) {
            res = max(res, i-mp[sum]);
        } else 
            mp[sum] = i;
    }
    return res;
}