// Prefix Sum with Hashing
// For positive and negative numbers
int lenOfLongSubarr(int nums[],  int n, int k) 
{ 
    unordered_map<int,int> mp;
    int res = 0, sum = 0;
    mp[sum] = -1;
    for(int i=0; i<n; i++) {
        sum += nums[i];
        if(mp.find(sum-k) != mp.end()) {
            res = max(res, i-mp[sum-k]);
        }
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return res;
} 

// For Only Positive Numbers (Non Negative n Non Zero)
// Two Pointer
int lenOfLongSubarr(int nums[],  int n, int k) 
{ 
    int res = 0, sum = 0;
    int l = 0;
    for(int h=0; h<n; h++) {
        sum += nums[h];
        while(sum > k && l <= h) {
            sum -= nums[l];
            l++;
        }
        if(sum == k) {
            res = max(res, h-l+1);
        }
    }
    return res;
} 