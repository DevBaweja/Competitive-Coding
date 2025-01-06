// Bit Manipulation
// Time - O(n*log(n)(sorting) + (2^n)*n)
// Inserting - log(k) so, (2^n)*log(2^n) = (2^n)*n
// Space - O(n*(2^n)) n is multiplied for the size of nums
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    if(!n) return {};
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    int power = 1<<n;
    for(int val=0; val < power; val++) {
        vector<int> cur;
        for(int i=0; i<n; i++) {
            if(val & (1<<i)) 
                cur.push_back(nums[i]);
        }
        st.insert(cur);
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}

// Recursion and Backtracking
// Time - O((2^n)*n + n*log(n))
// Space - O(n*(2^n))
void subsetsWithDupUtil(vector<int> &nums, int index, int &n, vector<int> &cur, 
vector<vector<int>>& res) {
    res.push_back(cur);
    // It is like BFS, making multiple calls by adding element one by one
    // At each element it make sure subset of size 0,1,2... is created level by level wise
    for(int idx=index; idx<n; idx++){
        // Skip duplicates
        if(idx != index && nums[idx] == nums[idx-1]) continue;
        cur.push_back(nums[idx]);
        subsetsWithDupUtil(nums, idx+1, n, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    if (!n) return {};
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> cur;
    subsetsWithDupUtil(nums, 0, n, cur, res);
    return res;
}