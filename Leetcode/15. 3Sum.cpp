#include <bits/stdc++.h>
using namespace std;

// Sorting and Two Pointer 
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 1; i++)
    {
        int target = -nums[i];
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int subsum = nums[left] + nums[right];
            if (subsum < target)
                left++;
            if (subsum > target)
                right--;
            if (subsum == target)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left + 1] == nums[left])
                    left++;
                while (left < right && nums[right - 1] == nums[right])
                    right--;
                left++;
                right--;
            }
        }

        while (i < n - 1 && nums[i] == nums[i + 1])
            i++;
    }
    return res;
}

// Two Pointer and Not Iterating over repeated elements -  Most simpler
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i=0; i<n-2; i++) {
        // Two Pointer
        int target = -nums[i];
        int j=i+1, k=n-1;
        while(j<k) {
            int sum = nums[j]+nums[k];
            if(sum == target) {
                res.push_back({nums[i],nums[j],nums[k]});
                j++; k--;
                while(j<k && nums[j-1] == nums[j])
                    j++;
                while(j<k && nums[k] == nums[k+1])
                    k--;
            }
            
            if(sum < target)
                j++;
            if(sum > target)
                k--;
        }
        while(i<n-3 && nums[i] == nums[i+1])
            i++;
    }
    return res;
}

// Simpler Two Pointer (Not optimized for inner loops)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> res;
    for(int i=0; i<n-2; i++) {
        // Two Pointer
        int target = -nums[i];
        int j=i+1, k=n-1;
        while(j<k) {
            int sum = nums[j]+nums[k];
            if(sum == target) {
                res.insert({nums[i],nums[j],nums[k]});
                j++; k--;
            }
            if(sum < target)
                j++;
            if(sum > target)
                k--;
        }
        while(i<n-3 && nums[i] == nums[i+1])
            i++;
    }
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}

// Two Pointer and No Duplicate
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++) {
    
        if(i>0 && nums[i] == nums[i-1]) continue;
        int target = -nums[i];
        int j = i+1, k = n-1;
        while(j<k) {
            int sum = nums[j]+nums[k];
            if(sum < target)
                j++;
            else if(sum > target)
                k--;
            else {
                res.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while(j<k && nums[j-1] == nums[j]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return res;
}