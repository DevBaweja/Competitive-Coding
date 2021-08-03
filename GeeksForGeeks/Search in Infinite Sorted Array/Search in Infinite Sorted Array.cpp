#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &A, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int key;
    cin >> key;

    int low = 0, high = 1;
    int val = A[high];
    while (val < key)
    {
        low = high + 1;
        high = 2 * high;
        val = A[high];
    }

    cout << binarySearch(A, low, high, key);
    return 0;
}