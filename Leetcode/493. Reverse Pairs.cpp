#include <bits/stdc++.h>
using namespace std;

// Brute Force
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count += nums[i] > 2ll * nums[j];
        }
    }
    return count;
}

// Using Merge Sort and Binary Search
typedef long long lll;
class Solution {
public:

    // Just larger element
    int binarySearch(vector<lll> &a, int l, int h, lll target) {
        int n = h-l+1;
        vector<lll> b(n);
        for(int i=l; i<=h; i++)
            b[i-l] = a[i];
        int x = 0, y = n-1;
        while(x <= y) {
            int m = (y-x)/2 + x;
            if(b[m] <= target)
                x = m+1;
            else
                y = m-1;
        }
        return x;
    }

    void merge(vector<lll>& nums,int l, int h, int ll, int hh, int& inv) {
        int n = h-l+1, m = hh-ll+1;
        vector<lll> a(n), b(m);
        for(int i=l; i<=h; i++)
            a[i-l] = nums[i];
        for(int j=ll; j<=hh; j++)
            b[j-ll] = nums[j];
        
        vector<lll> res(n+m);
        int i=0, j=0, k=0;
        int one = 0;
        while(i<n && j<m) {
            if(one == j) {
                // Taking every element once
                if(a[i] > (long long)2 *b[j]) {
                    inv += n-i;
                } else {
                    // Can reduce binary search
                    int res = binarySearch(a, 0, n-1, (long long)2*b[j]);   
                    inv += n-res;
                    // int res = binarySearch(a, i, n-1, (long long)2*b[j]); 
                    // inv += n-res-i;
                    
                }
                one++;
            }
            if(a[i] <= b[j]) {
                res[k++] = a[i++];
            } else {
                res[k++] = b[j++];
            }
        }
        while(i<n)
            res[k++] = a[i++];
        while(j<m)
            res[k++] = b[j++];

        for(int k=0; k<n+m; k++)
            nums[k+l] = res[k];
    
    }
    void mergeSort(vector<lll>& nums, int l, int h, int &inv) {
        if(l >= h)
            return;
        int m = (h-l)/2 + l;
        mergeSort(nums, l, m, inv);
        mergeSort(nums, m+1, h, inv);
        merge(nums, l, m, m+1, h, inv);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<lll> nm(n);
        for(int i=0; i<n; i++)
            nm[i] = nums[i];
        int inv = 0;
        mergeSort(nm, 0, n-1, inv);
        return inv;
    }
};

// Using Merge Sort and Two Pointer
void merge(vector<lll>& nums,int l, int h, int ll, int hh, int& inv) {
    int n = h-l+1, m = hh-ll+1;
    vector<lll> a(n), b(m);
    for(int i=l; i<=h; i++)
        a[i-l] = nums[i];
    for(int j=ll; j<=hh; j++)
        b[j-ll] = nums[j];
    
    int p = 0, q = 0;
    while(p<n && q<m) {
        // Taking every element once
        if(a[p] > (long long)2 *b[q]) {
            inv += n-p;
            q++;
        } else {
            p++;
        }
    }
    
    vector<lll> res(n+m);

    int i=0, j=0, k=0;
    while(i<n && j<m) {
        if(a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    while(i<n)
        res[k++] = a[i++];
    while(j<m)
        res[k++] = b[j++];

    for(int k=0; k<n+m; k++)
        nums[k+l] = res[k];

}
void mergeSort(vector<lll>& nums, int l, int h, int &inv) {
    if(l >= h)
        return;
    int m = (h-l)/2 + l;
    mergeSort(nums, l, m, inv);
    mergeSort(nums, m+1, h, inv);
    merge(nums, l, m, m+1, h, inv);
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<lll> nm(n);
    for(int i=0; i<n; i++)
        nm[i] = nums[i];
    int inv = 0;
    mergeSort(nm, 0, n-1, inv);
    return inv;
}

// Using Merge Sort and Two Pointer
void merge(vector<lll>& nums,int l, int h, int ll, int hh, int& inv) {
    int n = h-l+1, m = hh-ll+1;
    vector<lll> a(n), b(m);
    for(int i=l; i<=h; i++)
        a[i-l] = nums[i];
    for(int j=ll; j<=hh; j++)
        b[j-ll] = nums[j];
    
    int p = 0, q = 0;
    for(int p=0; p<n; p++) {
        while(q < m && a[p] > (long long)2 *b[q])
            q++;
        inv += q;
    }
    
    vector<lll> res(n+m);

    int i=0, j=0, k=0;
    while(i<n && j<m) {
        if(a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    while(i<n)
        res[k++] = a[i++];
    while(j<m)
        res[k++] = b[j++];

    for(int k=0; k<n+m; k++)
        nums[k+l] = res[k];

}
void mergeSort(vector<lll>& nums, int l, int h, int &inv) {
    if(l >= h)
        return;
    int m = (h-l)/2 + l;
    mergeSort(nums, l, m, inv);
    mergeSort(nums, m+1, h, inv);
    merge(nums, l, m, m+1, h, inv);
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<lll> nm(n);
    for(int i=0; i<n; i++)
        nm[i] = nums[i];
    int inv = 0;
    mergeSort(nm, 0, n-1, inv);
    return inv;
}