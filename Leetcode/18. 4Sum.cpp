// Two Pointer - Extension of 3 sum
typedef long long ll;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                // Two Pointer
                ll target = t*1ll-(nums[i]+nums[j]);
                int l=j+1, h=n-1;
                while(l<h) {
                    int sum = nums[l]+nums[h];
                    if(sum == target) {
                        res.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++; h--;
                        while(l<h && nums[l-1] == nums[l])
                            l++;
                        while(l<h && nums[h] == nums[h+1])
                            h--;
                    }
                    
                    if(sum < target)
                        l++;
                    if(sum > target)
                        h--;
                }
                while(j<n-3 && nums[j] == nums[j+1])
                    j++;
            }
            while(i<n-4 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};