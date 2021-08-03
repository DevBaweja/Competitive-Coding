#include <bits/stdc++.h>
using namespace std;

int partition(char a[], int el, int l, int h)
{
    int p = l;
    for (int j = l; j < h; j++)
    {
        if (a[j] < el)
            swap(a[p++], a[j]);
        else if (a[j] == el)
            swap(a[j--], a[h]);
    }
    swap(a[p], a[h]);
    return p;
}

void matchPairsUtil(char nuts[], char bolts[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition(nuts, bolts[high], low, high);
    int q = partition(bolts, nuts[p], low, high);
    matchPairsUtil(nuts, bolts, low, p - 1);
    matchPairsUtil(nuts, bolts, p + 1, high);
}

void matchPairs(char nuts[], char bolts[], int n)
{
    matchPairsUtil(nuts, bolts, 0, n - 1);
}