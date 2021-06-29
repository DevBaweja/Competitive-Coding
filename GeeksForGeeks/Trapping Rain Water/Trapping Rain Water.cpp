#include <bits/stdc++.h>
using namespace std;

// Prefix Sum
int trappingWater(int arr[], int n)
{
    vector<int> left(n);
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
    vector<int> right(n);
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    int count = 0;
    for (int i = 0; i < n; i++)
        count += min(left[i], right[i]) - arr[i];
    return count;
}

int main()
{
    int n = 6;
    int arr[] = {3, 0, 0, 2, 0, 4};
    cout << trappingWater(arr, n);
    return 0;
}