#include <bits/stdc++.h>
using namespace std;

int makeProductOne(int arr[], int n)
{
    int neg = 0;
    bool zero = false;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (!el)
        {
            zero = true;
            sum++;
        }
        else if (el > 0)
        {
            sum += el - 1;
        }
        else
        {
            neg++;
            sum += -el - 1;
        }
    }

    if (neg % 2 && !zero)
        sum += 2;

    return sum;
}