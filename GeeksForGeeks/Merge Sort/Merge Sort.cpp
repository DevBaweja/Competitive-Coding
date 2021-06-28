#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int s1 = m - l + 1, s2 = r - m;
    int L[s1], R[s2];
    for (int i = l; i <= m; i++)
        L[i - l] = arr[i];
    for (int j = m + 1; j <= r; j++)
        R[j - m - 1] = arr[j];

    int k = l, i = 0, j = 0;

    while (i < s1 && j < s2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < s1)
        arr[k++] = L[i++];
    while (j < s2)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
int main()
{
    int n = 5;
    int arr[] = {4, 1, 3, 9, 7};
    mergeSort(arr, 0, n - 1);
    for (int el : arr)
        cout << el << " ";
    return 0;
}