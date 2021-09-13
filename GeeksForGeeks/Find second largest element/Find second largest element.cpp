#include <bits/stdc++.h>
using namespace std;

int print2largest(int arr[], int n)
{
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (el > first)
        {
            second = first;
            first = el;
        }
        else if (el != first && el > second)
            second = el;
    }
    if (second == INT_MIN)
        second = -1;
    return second;
}