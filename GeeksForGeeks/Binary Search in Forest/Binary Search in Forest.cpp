#include <bits/stdc++.h>
using namespace std;

int cut_at_height(int tree[], int n, int cut)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (tree[i] > cut)
            sum += tree[i] - cut;
    return sum;
}

int find_height(int tree[], int n, int k)
{
    int low = 0;
    int high = *max_element(tree, tree + n);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = cut_at_height(tree, n, mid);
        if (sum == k)
            return mid;
        if (sum > k)
            low = mid + 1;
        if (sum < k)
            high = mid - 1;
    }
    return -1;
}