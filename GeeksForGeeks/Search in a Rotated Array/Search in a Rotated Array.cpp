#include <bits/stdc++.h>
using namespace std;

int search(int A[], int l, int h, int key)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (A[mid] == key)
            return mid;
        // left sorted
        else if (A[l] <= A[mid])
        {
            if (A[l] <= key && key <= A[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        // right sorted
        else if (A[mid] <= A[h])
        {
            if (A[mid] <= key && key <= A[h])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
    return -1;
}