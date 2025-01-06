#include <bits/stdc++.h>
using namespace std;

// Time - n+m
// Space - O(1)
void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    vector<int> res(m+n);
    int i=0, j=0; 
    int k = 0;
    while(i<n && j<m) {
        if(nums1[i] <= nums2[j]) {
            res[k++] = nums1[i++];
        }
        else {
            res[k++] = nums2[j++];
        }
    }
    while(i<n)
        res[k++] = nums1[i++];
    while(j<m)
        res[k++] = nums2[j++];
    for(int p=0; p<n+m; p++)
        nums1[p] = res[p];
}

// Time - min(n,m) + n*log(n) + m*log(m)
// Space - O(1)
void merge(vector<int>& nums, int n, vector<int>& nums2, int m) {
    vector<int> nums1(n);
    for(int i=0; i<n; i++)
        nums1[i] = nums[i];

    int l = 0, r = n-1;
    while(l < m && r >= 0 && nums1[r] > nums2[l]) {
            swap(nums1[r--], nums2[l++]);
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for(int i=0; i<n; i++) {
        nums[i] = nums1[i];
    }
    for(int j=0; j<m; j++) {
        nums[n+j] = nums2[j];
    }
}

// Time - log(n+m) * (n+m)
void merge(vector<int>& nums, int n, vector<int>& nums2, int m) {
    for(int i=n; i<n+m; i++)
        nums[i] = nums2[i-n];
    // Shell Shot Inspired Gap Method
    int gap = (n+m)/2 + (n+m)%2;
    while(gap > 0) {
        int l = 0, r = gap;
        while(r < n+m) {
            if(nums[l] > nums[r])
                swap(nums[l], nums[r]);
            l++; r++;
        }
        if(gap == 1)
            break;
        gap = (gap/2) + (gap%2);
    }

}

// Iterate from end

// Time - O(n+m)
// Space - O(1)
void merge(vector<int>& nums, int n, vector<int>& nums2, int m) {
    int k = n+m-1;
    int i = n-1, j = m-1;
    while(j >= 0) {
        if(i >= 0 && nums[i] > nums2[j]) {
            nums[k--] = nums[i--];
        }
        else {
            nums[k--] = nums2[j--];
        }
    }
}