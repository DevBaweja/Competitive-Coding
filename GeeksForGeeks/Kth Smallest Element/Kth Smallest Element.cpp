#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    sort(arr, arr + r + 1);
    return arr[k - 1];
}

// Priority Queue
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= r; i++)
        pq.push(arr[i]);
    int count = 0;
    while (!pq.empty())
    {
        count++;
        if (count == k)
            return pq.top();
        pq.pop();
    }
}

// Map and Frequency
int kthSmallest(int arr[], int l, int r, int k)
{
    map<int, int> m;
    for (int i = l; i <= r; i++)
        m[arr[i]]++;
    int count = 0;
    for (pair<int, int> el : m)
    {
        count += el.second;
        if (count == k)
            return el.first;
    }
}

// Quick Select Last Element Pivot
int partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
}

// Quick Select Random Element
int partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
}