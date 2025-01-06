// n2
int findMaximumXOR(vector<int>& nums) {
    // different bits
    int maxi = 0;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            maxi = max(maxi, nums[i]^nums[j]);
        }
    }
    return maxi;
}

int findMaximumXOR(vector<int>& nums) {
    unordered_set<int> s;
    for(int el: nums)
        s.insert(el);
    vector<int> arr;
    for(int el: s)
        arr.push_back(el);
    // different bits
    int maxi = 0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            maxi = max(maxi, arr[i]^arr[j]);
        }
    }
    return maxi;
}