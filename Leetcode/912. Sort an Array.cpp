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