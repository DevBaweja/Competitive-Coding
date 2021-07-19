#include <bits/stdc++.h>
using namespace std;

void constructSTUtil(int arr[], int *st, int l, int h, int pos)
{
    if (l == h)
    {
        st[pos] = arr[l];
        return;
    }
    int mid = (l + h) / 2;

    constructSTUtil(arr, st, l, mid, 2 * pos + 1);
    constructSTUtil(arr, st, mid + 1, h, 2 * pos + 2);

    st[pos] = min(st[2 * pos + 1], st[2 * pos + 2]);
}

int *constructST(int arr[], int n)
{
    int h = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, h) - 1;
    int *st = new int[size];
    int pos = 0;
    constructSTUtil(arr, st, 0, n - 1, pos);
    return st;
}

int RMQUtil(int st[], int l, int h, int ql, int qh, int pos)
{
    // total overlap
    if (ql <= l && qh >= h)
        return st[pos];
    // no overlap
    if (ql > h || qh < l)
        return INT_MAX;
    int mid = (l + h) / 2;
    return min(RMQUtil(st, l, mid, ql, qh, 2 * pos + 1),
               RMQUtil(st, mid + 1, h, ql, qh, 2 * pos + 2));
}

int RMQ(int st[], int n, int ql, int qh)
{
    int pos = 0;
    return RMQUtil(st, 0, n - 1, ql, qh, pos);
}