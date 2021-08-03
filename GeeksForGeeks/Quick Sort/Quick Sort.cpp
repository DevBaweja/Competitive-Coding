#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}
int partition(int arr[], int low, int high)
{
    int el = arr[high];
    int p = low;
    for (int j = low; j < high; j++)
        if (arr[j] < el)
            swap(arr[p++], arr[j]);
    swap(arr[p], arr[high]);
    return p;
}