#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

void merge(vector<int> &nums, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0, k = low; i < n1; i++, k++)
        left[i] = nums[k];
    for (int j = 0, k = mid + 1; j < n2; j++, k++)
        right[j] = nums[k];
    int k = low;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }

    while (i < n1)
        nums[k++] = left[i++];
    while (j < n2)
        nums[k++] = right[j++];
}

vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return nums;
}


// Bubble Sort
// Time - O(n^2)
// Space - O(1)
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n-1; i++) {
        for(int j=1; j<n; j++) {
            if(nums[j-1] > nums[j])
                swap(nums[j-1], nums[j]);
        }
    }
    return nums;
}
// Optimal Bubble Sort
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n-1; i++) {
        bool flag = false;
        // Reduced comparsion
        for(int j=1; j<n-i; j++) {
            if(nums[j-1] > nums[j]) {
                swap(nums[j-1], nums[j]);
                flag = true;
            }
        }
        // No swap then break
        if(!flag)
            break;
    }
    return nums;
}

// Selection Sort
// Time - O(n^2)
// Space - O(1)
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n-1; i++) {
        int mini = i;
        for(int j=i+1; j<n; j++) {
            if(nums[j] < nums[mini]) {
                mini = j;
            }                
        }
        if(i != mini)
            swap(nums[i], nums[mini]);
    }
    return nums;
}

// Insertion Sort
// Time - O(n^2)
// Space - O(1)
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        for(int j=i; j>0 && nums[j-1] > nums[j]; j--) {
            swap(nums[j-1], nums[j]);
        }
    }
    return nums;
}

// Optimize Insertion Sort
// Time - O(n^2)
// Space - O(1)
// Avoid swap, replace element
// We can also use binary search to find of the element in sorted array
// But it will not reduce time complexity as linear shifting will still be required
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        int key = nums[i];
        int j = i-1;
        while(j>=0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
    return nums;
}


// Merge Sort
void merge(vector<int>& nums, int l, int h, int ll, int hh) {
    int n = h-l+1; int m = hh-ll+1;
    vector<int> a(n), b(m);
    for(int i=l; i<=h; i++)
        a[i-l] = nums[i];
    for(int j=ll; j<=hh; j++)
        b[j-ll] = nums[j];
    
    vector<int> res(n+m);
    int i = 0, j = 0, k = 0;
    while(i<n && j<m) {
        if(a[i] < b[j]) {
            res[k++] = a[i++];
        }
        else {
            res[k++] = b[j++];
        }
    }
    while(i<n) {
        res[k++] = a[i++];
    }
    while(j<m) {
        res[k++] = b[j++];
    }

    for(int idx=0; idx<res.size(); idx++) {
        nums[idx+l] = res[idx];
    }
}

void mergeSort(vector<int>& nums, int l, int h) {
    if(l >= h)
        return;
    int m = (l+h)/2;
    mergeSort(nums, l, m);
    mergeSort(nums, m+1, h);
    merge(nums, l, m, m+1, h);
}
vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    mergeSort(nums, 0, n-1);
    return nums;
}