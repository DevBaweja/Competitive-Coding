// Sorting and Hashing
// Time - O(nlog(n))
// Space - O(n)
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> mp;
    int res = 0;
    sort(nums.begin(), nums.end());
    for(int el: nums) {
        if(mp.find(el-1) != mp.end()) {
            mp[el] = mp[el-1]+1;
            res = max(res, mp[el]);
        }
        else 
            mp[el] = 1;
    }
    return res;
}

// Sorting
// Time - O(nlog(n))
// Space - O(n)
int longestConsecutive(vector<int>& dnums) {
    unordered_map<int, int> mp;
    unordered_set<int> dup(dnums.begin(), dnums.end());
    vector<int> nums(dup.begin(), dup.end());
    int n = nums.size();
    if(!n) return n;
    sort(nums.begin(), nums.end());
    
    int res = 1, cur = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] == nums[i-1]+1) {
            cur++;
        }
        else {
            res = max(res, cur);
            cur = 1;
        }
    }
    res = max(res, cur);
    return res;
}

// Sorting
// Time - O(nlog(n))
// Space - O(1)
int longestConsecutive(vector<int>& nums) {
    // If duplicate
    int n = nums.size();
    if(!n) return n;
    unordered_map<int, int> mp;
    sort(nums.begin(), nums.end());
    
    int res = 1, cur = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] == nums[i-1])
            continue;
        if(nums[i] == nums[i-1]+1) {
            cur++;
        }
        else {
            res = max(res, cur);
            cur = 1;
        }
    }
    res = max(res, cur);
    return res;
}

// Hashing and Combining
// Time - O(n * n)
// Space - O(1)
// Time Complexity
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> mp;
    int res = 0;
    for(int el: nums) {
        if(mp.find(el) != mp.end()) {
            continue;
        }
        int l = 0, r = 0;
        if(mp.find(el+1) != mp.end()) {
            r = mp[el+1];
        }
        if(mp.find(el-1) != mp.end()) {
            l = mp[el-1];
        }
        int newv = l+r+1;
        int tr = el+1, tl = el-1;
        while(mp.find(tr) != mp.end()) {
            mp[tr++] = newv;
        }
        while(mp.find(tl) != mp.end()) {
            mp[tl--] = newv;
        }
        res = max(res, newv);
        mp[el] = newv;
    }
    return res;
}

// Identify Starting Element
// Time - O(2*n) - inner loop is not O(n) it can be atmost twice
// Space - O(n)
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(!n) return n;
    unordered_set<int> st;
    for(int el: nums)
        st.insert(el);
    int res = 1;
    for(auto el: st) {
        // Identify starting point
        if(st.find(el-1) == st.end()) {
            int tel = el+1;
            int count = 1;
            while(st.find(tel++) != st.end()) {
                count++;
                res = max(res, count);
            }
        }
    }
    return res;
}

// TODO Disjoint Set