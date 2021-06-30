#include <bits/stdc++.h>
using namespace std;

int find(int in[], int f, int n)
{
    for (int i = 0; i < n; i++)
        if (in[i] == f)
            return i;
    return -1;
}

void printPostOrder(int in[], int pre[], int n)
{
    // 4 2 5 1 3 6
    // 1 2 4 5 3 6
    int f = find(in, pre[0], n);
    if (f != 0)
        printPostOrder(in, pre + 1, f);
    if (f != n - 1)
        printPostOrder(in + f + 1, pre + f + 1, n - f - 1);
    cout << pre[0] << " ";
}