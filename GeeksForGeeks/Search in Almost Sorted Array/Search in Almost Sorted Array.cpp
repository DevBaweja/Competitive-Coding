#include <bits/stdc++.h>
using namespace std;

int almostSorted(vector<int> &A, int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (A[mid] == key)
            return key;
        if (mid > low && A[mid - 1] == key)
            return mid - 1;
        if (mid < high && A[mid + 1] == key)
            return mid + 1;
        if (A[mid] <= key)
            low = mid + 2;
        else
            high = mid - 2;
    }
    return -1;
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
    cout << almostSorted(A, n, key);
    return 0;
}